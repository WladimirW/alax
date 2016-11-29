// NOTE: http://stackoverflow.com/questions/40849420/media-foundation-amr-decode

#include <sdkddkver.h>

#include <stdio.h>
#include <tchar.h>

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

#include <atlbase.h>
#include <atlstr.h>

#include <mfapi.h>
#include <mfidl.h>
#include <mfreadwrite.h>

#pragma comment(lib, "mfplat.lib")
#pragma comment(lib, "mfuuid.lib")
#pragma comment(lib, "mfreadwrite.lib")

int main()
{
	_ATLTRY
	{
		ATLENSURE_SUCCEEDED(MFStartup(MF_VERSION));
		CComPtr<IMFSourceReader> pReader;
		CComPtr<IMFMediaType> pAudioType;
		static const LPCTSTR g_pszPath = 
			_T("D:\\Projects\\Alax.Info\\Repository-Private\\Utilities\\MediaFoundation\\ProbeMediaSource\\example.amr");
		ATLENSURE_SUCCEEDED(MFCreateSourceReaderFromURL(g_pszPath, NULL, &pReader));
		ATLENSURE_SUCCEEDED(pReader->SetStreamSelection(MF_SOURCE_READER_ALL_STREAMS, false));
		ATLENSURE_SUCCEEDED(pReader->SetStreamSelection(MF_SOURCE_READER_FIRST_AUDIO_STREAM, true));
		ATLENSURE_SUCCEEDED(pReader->GetCurrentMediaType(MF_SOURCE_READER_FIRST_AUDIO_STREAM, &pAudioType));
		UINT32 numChannels, sampleRate;
		ATLENSURE_SUCCEEDED(pAudioType->GetUINT32(MF_MT_AUDIO_NUM_CHANNELS, &numChannels));
		ATLENSURE_SUCCEEDED(pAudioType->GetUINT32(MF_MT_AUDIO_SAMPLES_PER_SECOND, &sampleRate));
		_tprintf(_T("numChannels %d, sampleRate %d\n"), numChannels, sampleRate);
		// NOTE: Sample output:
		//       numChannels 1, sampleRate 8000
	}
	_ATLCATCHALL()
	{
		_tprintf(_T("Fatal Error\n"));
	}
    return 0;
}

