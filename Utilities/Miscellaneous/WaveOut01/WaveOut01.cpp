// NOTE: https://stackoverflow.com/a/49673867/868014

#define _WIN32_IE 0x0500
#define _WIN32_WINNT 0x0501
#define WINVER _WIN32_WINNT

#include <windows.h>
#include <mmsystem.h>
#include <commctrl.h>

#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "comctl32.lib")

short freq, ampl;



typedef struct {
    long chnl, smpl, bits, size, swiz;
    void *sink, *data[2];
} WAVE;



LRESULT APIENTRY WndProc(HWND hWnd, UINT uMsg, WPARAM wPrm, LPARAM lPrm) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_NOTIFY:
            switch (((NMHDR*)lPrm)->idFrom) {
                case 2:
                    freq = ((NMUPDOWN*)lPrm)->iPos;
                    break;

                case 4:
                    ampl = ((NMUPDOWN*)lPrm)->iPos;
                    break;
            }
            return 0;

        default:
            break;
    }
    return DefWindowProc(hWnd, uMsg, wPrm, lPrm);
}



void FillBuf(WAVE *wave, short freq, short ampl, long *phaz) {
    int16_t *data = (int16_t *) wave->data[wave->swiz ^= 1];
    float tone = 1.0f * freq / wave->smpl;
    long iter;

    for(iter = 0; iter < wave->size; iter++)
        data[iter] = ((long)(tone * (iter + *phaz)) & 1)? ampl : -ampl;

    *phaz = *phaz + iter;//2.0 * frac(0.5 * tone * (iter + *phaz)) / tone;
}



DWORD APIENTRY WaveFunc(LPVOID data) 
{
    WAVEHDR *whdr;
    WAVE *wave;
    intptr_t *sink;
    long size, phaz = 0;

    wave = (WAVE*)data;
    whdr = (WAVEHDR*)(sink = (intptr_t*) wave->sink)[1];
    size = wave->chnl * wave->size * (wave->bits >> 3);

	HWAVEOUT hWaveOut = (HWAVEOUT) sink[0];
	HANDLE hEvent = (HANDLE)sink[2];

    whdr[0].dwBufferLength = whdr[1].dwBufferLength = size;
    whdr[0].dwFlags        = whdr[1].dwFlags        = 0;
    whdr[0].dwLoops        = whdr[1].dwLoops        = 0;
    whdr[0].lpData = (LPSTR)(wave->data[0] = calloc(1, size));
    whdr[1].lpData = (LPSTR)(wave->data[1] = calloc(1, size));

    ResetEvent(hEvent);

	assert(wave->swiz == 0);
    FillBuf(wave, freq, ampl, &phaz);
    waveOutPrepareHeader(hWaveOut, &whdr[1], sizeof (WAVEHDR));
    waveOutWrite(hWaveOut, &whdr[1], sizeof (WAVEHDR));

	assert(wave->swiz == 1);
    FillBuf(wave, freq, ampl, &phaz);
    waveOutPrepareHeader(hWaveOut, &whdr[0], sizeof (WAVEHDR));
    waveOutWrite(hWaveOut, &whdr[0], sizeof (WAVEHDR));

	for(; ; )
	{
		WaitForSingleObject(hEvent, INFINITE);
	    ResetEvent(hEvent);
		for(long index = 0; index < 2; index++)
			if(whdr[index].dwFlags & WHDR_DONE)
			{
				wave->swiz = index ^ 1;
				//waveOutUnprepareHeader(hWaveOut, &whdr[wave->swiz], sizeof (WAVEHDR));
				FillBuf(wave, freq, ampl, &phaz);
				//waveOutPrepareHeader(hWaveOut, &whdr[wave->swiz], sizeof (WAVEHDR));
				waveOutWrite(hWaveOut, &whdr[wave->swiz], sizeof (WAVEHDR));
			}
	}
    return 0;
}



int main() //APIENTRY WinMain(HINSTANCE inst, HINSTANCE prev, LPSTR args, int show) 
{
    WNDCLASSEX wndc = {sizeof(wndc), CS_HREDRAW | CS_VREDRAW, WndProc, 0, 0,
                       NULL, //inst, 
						LoadIcon(0, IDI_HAND), LoadCursor(0, IDC_ARROW),
                       (HBRUSH)(COLOR_BTNFACE + 1), 0, L"-", 0};
    INITCOMMONCONTROLSEX icct = {sizeof(icct), ICC_STANDARD_CLASSES};
	MSG pmsg = { };

    HWND mwnd, cwnd, spin;
    DWORD thrd;
    WAVEFORMATEX wfmt;
    intptr_t sink[3];
    WAVE wave = {1, 44100, 16, 4096, 0, sink};

//    AllocConsole();
//    freopen("CONOUT$", "wb", stdout);

    InitCommonControlsEx(&icct);
    RegisterClassEx(&wndc);
    mwnd = CreateWindowEx(0, wndc.lpszClassName, L" ",
                          WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                          CW_USEDEFAULT, CW_USEDEFAULT, 320, 240,
                          HWND_DESKTOP, 0, wndc.hInstance, 0);


    cwnd = CreateWindowEx(WS_EX_CLIENTEDGE, WC_EDIT, 0, ES_AUTOHSCROLL
                        | ES_WANTRETURN | ES_MULTILINE | ES_NUMBER | WS_CHILD
                        | WS_VISIBLE, 10, 10, 100, 24, mwnd, (HMENU)1, 0, 0);
    SendMessage(cwnd, EM_LIMITTEXT, 9, 0);
    spin = CreateWindowEx(0, UPDOWN_CLASS, 0, UDS_HOTTRACK | UDS_NOTHOUSANDS
                        | UDS_ALIGNRIGHT | UDS_SETBUDDYINT | UDS_ARROWKEYS
                        | WS_CHILD | WS_VISIBLE, 0, 0, 0, 0, mwnd, (HMENU)2, 0, 0);
    SendMessage(spin, UDM_SETBUDDY, (WPARAM)cwnd, 0);
    SendMessage(spin, UDM_SETRANGE32, (WPARAM)20, (LPARAM)22050);
    SendMessage(spin, UDM_SETPOS32, 0, (LPARAM)(freq = 750 + 0 * 400));


    cwnd = CreateWindowEx(WS_EX_CLIENTEDGE, WC_EDIT, 0, ES_AUTOHSCROLL
                        | ES_WANTRETURN | ES_MULTILINE | ES_NUMBER | WS_CHILD
                        | WS_VISIBLE, 10, 44, 100, 24, mwnd, (HMENU)3, 0, 0);
    SendMessage(cwnd, EM_LIMITTEXT, 9, 0);
    spin = CreateWindowEx(0, UPDOWN_CLASS, 0, UDS_HOTTRACK | UDS_NOTHOUSANDS
                        | UDS_ALIGNRIGHT | UDS_SETBUDDYINT | UDS_ARROWKEYS
                        | WS_CHILD | WS_VISIBLE, 0, 0, 0, 0, mwnd, (HMENU)4, 0, 0);
    SendMessage(spin, UDM_SETBUDDY, (WPARAM)cwnd, 0);
    SendMessage(spin, UDM_SETRANGE32, (WPARAM)0, (LPARAM)32767);
    SendMessage(spin, UDM_SETPOS32, 0, (LPARAM)(ampl = 7500 + 0 * 32767));


    wfmt.wFormatTag = WAVE_FORMAT_PCM;
    wfmt.nChannels = (WORD) wave.chnl;
    wfmt.nSamplesPerSec = (DWORD) wave.smpl;
    wfmt.nAvgBytesPerSec = (DWORD) (((wave.chnl * wave.bits) >> 3) * wave.smpl);
    wfmt.nBlockAlign = (WORD) ((wave.chnl * wave.bits) >> 3);
    wfmt.wBitsPerSample = (WORD) wave.bits;
    wfmt.cbSize = 0;
    sink[1] = (intptr_t)calloc(2, sizeof(WAVEHDR));
    waveOutOpen((LPHWAVEOUT)&sink[0], WAVE_MAPPER, &wfmt,
                 sink[2] = (intptr_t)CreateEvent(0, 1, 0, 0), 0,
                 CALLBACK_EVENT);
    SetThreadPriority(CreateThread(0, 0, WaveFunc, &wave, 0, &thrd),
                      THREAD_PRIORITY_NORMAL + 0 * THREAD_PRIORITY_TIME_CRITICAL);

    while (pmsg.message != WM_QUIT) {
        if (PeekMessage(&pmsg, 0, 0, 0, PM_REMOVE)) {
            TranslateMessage(&pmsg);
            DispatchMessage(&pmsg);
            continue;
        }
        Sleep(1);
    }

	// TODO: waveOutUnprepareHeader and thread termination

    waveOutClose((HWAVEOUT)sink[0]);
    fclose(stdout);
    FreeConsole();

    exit(pmsg.wParam);
    return 0;
}