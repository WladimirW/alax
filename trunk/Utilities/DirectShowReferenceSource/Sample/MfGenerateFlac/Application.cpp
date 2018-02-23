////////////////////////////////////////////////////////////
// Copyright (C) Roman Ryltsov, 2015-2018
// Created by Roman Ryltsov roman@alax.info
//
// A permission to use the source code is granted as long as reference to 
// source website http://alax.info is retained.

#include "stdafx.h"
#include "romf.h"
#import "libid:9E3ABA93-C8D8-41D3-B39E-29508FDE5757" raw_interfaces_only // AlaxInfoDirectShowReferenceSource

////////////////////////////////////////////////////////////
// CModule

class CModule :
	public CAtlExeModuleT<CModule>
{
public:
// CModule
	bool ParseCommandLine(LPCTSTR pszCommandLine, HRESULT* pnResult)
	{
		_A(pnResult);
		pszCommandLine;
		*pnResult = S_OK;
		return true;
	}
	HRESULT PreMessageLoop(int nShowCommand)
	{
		// NOTE: Suppress S_FALSE
		_C(__super::PreMessageLoop(nShowCommand));
		return S_OK;
	}
	VOID RunMessageLoop()
	{
		MF::CStartup Statup;
		#pragma region Media Source
		CComQIPtr<IMFMediaSource> pMediaSource;
		{
			using namespace AlaxInfoDirectShowReferenceSource;
			CComPtr<IAudioMediaSource> pAudioMediaSource;
			__C(pAudioMediaSource.CoCreateInstance(__uuidof(AudioMediaSource)));
			// NOTE: https://stackoverflow.com/questions/48930499/how-do-i-encode-raw-48khz-32bits-pcm-to-flac-using-microsoft-media-foundation
			__C(pAudioMediaSource->SetMediaType(CComBSTR(MF::FormatIdentifier(MFAudioFormat_PCM)), 48828, 1, 32));
			__C(pAudioMediaSource->put_Duration((DOUBLE) 15.0));
			pMediaSource = pAudioMediaSource;
		}
		#pragma endregion 
		CComPtr<IMFSourceReader> pSourceReader;
		__C(MFCreateSourceReaderFromMediaSource(pMediaSource, NULL, &pSourceReader));
		MF::CMediaType pMediaType;
		__C(pSourceReader->GetCurrentMediaType(MF_SOURCE_READER_FIRST_AUDIO_STREAM, &pMediaType));
		pMediaType.Trace();
		SYSTEMTIME Time;
		GetLocalTime(&Time);
		const CString sFileName = AtlFormatString(_T("%04d%02d%02d-%02d%02d%02d.wav"), Time.wYear, Time.wMonth, Time.wDay, Time.wHour, Time.wMinute, Time.wSecond);
		CComPtr<IMFMediaSink> pMediaSink;
		CComPtr<IMFSinkWriter> pSinkWriter;
		{
			const CPath sPath = Combine(GetPathDirectory(GetModulePath()), sFileName);
			// NOTE: Sink Writer Attributes https://msdn.microsoft.com/en-us/library/windows/desktop/dd389284
			MF::CAttributes pAttributes;
			#if 1
				CComPtr<IMFByteStream> pByteStream;
				__C(MFCreateFile(MF_ACCESSMODE_WRITE, MF_OPENMODE_DELETE_IF_EXIST, MF_FILEFLAGS_NONE, CStringW(sPath), &pByteStream));
				__C(MFCreateWAVEMediaSink(pByteStream, pMediaType, &pMediaSink));
				__C(MFCreateSinkWriterFromMediaSink(pMediaSink, NULL, &pSinkWriter));
			#else
				pAttributes.Create(1);
				pAttributes[MF_TRANSCODE_CONTAINERTYPE] = MFTranscodeContainerType_WAVE;
				__C(MFCreateSinkWriterFromURL(sPath, NULL, pAttributes, &pSinkWriter));
			#endif
		}
		#if _DEVELOPMENT && FALSE
			MF::CMediaType pWriterReferenceMediaType;
			{
				MF::CTransform pTransform;
				__C(pTransform.m_p.CoCreateInstance(CLSID_CMSFLACEncMFT));
				pTransform.SetInputType(pMediaType);
				for(DWORD nTypeIndex = 0; ; nTypeIndex++)
				{
					MF::CMediaType pMediaType;
					if(!pTransform.GetOutputAvailableType(nTypeIndex, pMediaType))
						break;
					pMediaType.Trace();
					pWriterReferenceMediaType = pMediaType;
					break;
				}
			}
		#endif // _DEVELOPMENT

		MF::CMediaType pWriterMediaType;
		pWriterMediaType.Create();
		pWriterMediaType[MF_MT_MAJOR_TYPE] = MFMediaType_Audio;
		pWriterMediaType[MF_MT_SUBTYPE] = MFAudioFormat_FLAC;
		pWriterMediaType.CopyFrom(pMediaType, MF_MT_AUDIO_SAMPLES_PER_SECOND);
		pWriterMediaType.CopyFrom(pMediaType, MF_MT_AUDIO_NUM_CHANNELS);
		pWriterMediaType.CopyFrom(pMediaType, MF_MT_AUDIO_BITS_PER_SAMPLE);
		//pWriterMediaType[MF_MT_AUDIO_VALID_BITS_PER_SAMPLE] = pWriterMediaType.GetUINT32(MF_MT_AUDIO_BITS_PER_SAMPLE);
		//pWriterMediaType[MF_MT_ALL_SAMPLES_INDEPENDENT] = (UINT32) 1;

		//pWriterMediaType = pWriterReferenceMediaType;

		pWriterMediaType.Trace();
		DWORD nWriterStreamIndex = 0;
		if(!pMediaSink) // 0xC00D4A3B MF_E_STREAMSINKS_FIXED Stream Sinks cannot be added to or removed from this Media Sink because its set of streams is fixed.
			__C(pSinkWriter->AddStream(pWriterMediaType, &nWriterStreamIndex));
		__C(pSinkWriter->SetInputMediaType(nWriterStreamIndex, pMediaType, NULL));
		MF::CSinkWriterHelper::TraceTransformsT<MF::CSinkWriterHelper::CAudioTraceTraits>(pSinkWriter);
		const ULONG nTimeA = GetTickCount();
		__C(pSinkWriter->BeginWriting());
		for(; ; )
		{
			DWORD nStreamIndex, nStreamFlags;
			LONGLONG nTime;
			MF::CSample pSample;
			__C(pSourceReader->ReadSample(MF_SOURCE_READER_FIRST_AUDIO_STREAM, 0, &nStreamIndex, &nStreamFlags, &nTime, &pSample));
			_Z4(atlTraceGeneral, 4, _T("nStreamIndex %d, nStreamFlags %s, nTime %s, pSample 0x%p\n"), nStreamIndex, MF::FormatSourceReaderStreamFlags(nStreamFlags), MF::FormatNanoTime(nTime), pSample);
			if(pSample)
			{
				pSample.Trace();
				__C(pSinkWriter->WriteSample(nWriterStreamIndex, pSample));
			}
			if(nStreamFlags & MF_SOURCE_READERF_ENDOFSTREAM)
			{
				_A(!pSample);
				break;
			}
		}
		__C(pSourceReader->Flush(MF_SOURCE_READER_ALL_STREAMS));
		const ULONG nTimeB = GetTickCount();
		_tprintf(_T("Elapsed Time: %.2f seconds\n"), (DOUBLE) (nTimeB - nTimeA) / 1E3);
		__C(pSinkWriter->Finalize());
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	_ATLTRY
	{
		CModule Module;
		Module.WinMain(SW_SHOWNORMAL);
	}
	_ATLCATCH(Exception)
	{
		_tprintf(_T("Fatal Error 0x%08X\n"), (HRESULT) Exception);
	}
	return 0;
}

