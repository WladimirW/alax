#include "stdafx.h"

#include <codecapi.h>
#include <mfapi.h>
#include <mfidl.h>
#include <mfreadwrite.h>

#pragma comment(lib, "mfuuid.lib")
#pragma comment(lib, "mfplat.lib")
#pragma comment(lib, "mfreadwrite.lib")

#define __C ATLENSURE_SUCCEEDED

int _tmain(int argc, _TCHAR* argv[])
{
	__C(CoInitialize(NULL));
    __C(MFStartup(MF_VERSION, MFSTARTUP_FULL));
	{
		// NOTE: Tutorial: Using the Sink Writer to Encode Video https://msdn.microsoft.com/en-us/library/windows/desktop/ff819477

		LPCWSTR pszPath = L"D:\\Temp.mp4";

		// NOTE: MFCreateSinkWriterFromURL function https://msdn.microsoft.com/en-us/library/windows/desktop/dd388105
		CComPtr<IMFSinkWriter> pSinkWriter;
		__C(MFCreateSinkWriterFromURL(pszPath, NULL, NULL, &pSinkWriter));

		// NOTE: http://stackoverflow.com/questions/41447563/media-foundation-mp4-encoding-imfsinkwriter-doesnt-accept-pcm-input

		CComPtr<IMFMediaType> pMediaTypeOut;
		__C(MFCreateMediaType(&pMediaTypeOut));
		__C(pMediaTypeOut->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Audio)); 
		__C(pMediaTypeOut->SetGUID(MF_MT_SUBTYPE, MFAudioFormat_AAC));
		__C(pMediaTypeOut->SetUINT32(MF_MT_AUDIO_NUM_CHANNELS, 2));
		__C(pMediaTypeOut->SetUINT32(MF_MT_AUDIO_SAMPLES_PER_SECOND, 44100));
		__C(pMediaTypeOut->SetUINT32(MF_MT_AUDIO_BITS_PER_SAMPLE, 16));
		//__C(pMediaTypeOut->SetUINT32(MF_MT_ALL_SAMPLES_INDEPENDENT, 0));

		DWORD streamIndex;  
		__C(pSinkWriter->AddStream(pMediaTypeOut, &streamIndex));

		CComPtr<IMFMediaType> pMediaTypeIn;
		__C(MFCreateMediaType(&pMediaTypeIn)); 

		__C(pMediaTypeIn->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Audio));   
		__C(pMediaTypeIn->SetGUID(MF_MT_SUBTYPE, MFAudioFormat_PCM));

		__C(pMediaTypeIn->SetUINT32(MF_MT_AUDIO_NUM_CHANNELS, 2));
		__C(pMediaTypeIn->SetUINT32(MF_MT_AUDIO_SAMPLES_PER_SECOND, 44100));
		//__C(pMediaTypeIn->SetUINT32(MF_MT_AUDIO_BLOCK_ALIGNMENT, 4));
		//__C(pMediaTypeIn->SetUINT32(MF_MT_AUDIO_AVG_BYTES_PER_SECOND, 44100 * 4));
		__C(pMediaTypeIn->SetUINT32(MF_MT_AUDIO_BITS_PER_SAMPLE, 16));
		__C(pMediaTypeIn->SetUINT32(MF_MT_ALL_SAMPLES_INDEPENDENT, 1));

		__C(pSinkWriter->SetInputMediaType(streamIndex, pMediaTypeIn, NULL));   
		__C(pSinkWriter->BeginWriting());
	}
	return 0;
}

