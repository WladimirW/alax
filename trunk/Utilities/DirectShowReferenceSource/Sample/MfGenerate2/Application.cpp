////////////////////////////////////////////////////////////
// Copyright (C) Roman Ryltsov, 2015-2017
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
		CComPtr<IMFSourceResolver> pSourceResolver;
		__C(MFCreateSourceResolver(&pSourceResolver));
		#pragma region Media Source
		CComPtr<IMFMediaSource> pMediaSource;
		//{
		//	static const LPCTSTR g_pszPath = 
		//		_T("D:\\Projects\\Alax.Info\\Repository-Private\\Utilities\\DirectShow\\ReferenceSource\\_Media\\720p50-Small-V.mp4");
		//	MF_OBJECT_TYPE ObjectType;
		//	CComPtr<IUnknown> pMediaSourceUnknown;
		//	__C(pSourceResolver->CreateObjectFromURL(CStringW(g_pszPath), MF_RESOLUTION_MEDIASOURCE, NULL, &ObjectType, &pMediaSourceUnknown));
		//	_A(ObjectType == MF_OBJECT_MEDIASOURCE);
		//	pMediaSource = pMediaSourceUnknown;
		//	__D(pMediaSource, E_NOINTERFACE);
		//}
		CComPtr<IMFMediaSource> pVideoMediaSource, pAudioMediaSource;
		const BOOL g_bVideo = TRUE;
		const SIZE g_Extent = 
			{ 1920, 1080 };
			//{ 7680 / 2, 4320 / 2 };
			//{ 7680, 4320 };
		const LONG g_nFrameRateNumerator = 50000;
		const LONG g_nFrameRateDenominator = 1000;
		const LONG g_nVideoBitrate = (10 * 1000) * 1000; // MBps
		const BOOL g_bAudio = FALSE;
		const LONG g_nSampleRate = 48000;
		const LONG g_nChannelCount = 1;
		const LONG g_nBitDepth = 16;
		const LONG g_nAudioBitrate = 20 * 1000; // kBps
		const LONG g_nDuration = 1 * 60; // minutes
		#pragma region Video
		if(g_bVideo)
		{
			using namespace AlaxInfoDirectShowReferenceSource;
			CComPtr<IVideoMediaSource> pSource;
			__C(pSource.CoCreateInstance(__uuidof(VideoMediaSource)));
			__C(pSource->SetMediaType(g_Extent.cx, g_Extent.cy, CComVariant(_PersistHelper::StringFromIdentifier(MEDIASUBTYPE_RGB32))));
			//__C(pSource->SetMediaTypeAspectRatio(...));
			__C(pSource->SetMediaTypeRate(g_nFrameRateNumerator, g_nFrameRateDenominator));
			__C(pSource->put_Duration((DOUBLE) g_nDuration));
			pVideoMediaSource = pSource;
		}
		#pragma endregion 
		#pragma region Audio
		if(g_bAudio)
		{
			using namespace AlaxInfoDirectShowReferenceSource;
			CComPtr<IAudioMediaSource> pSource;
			__C(pSource.CoCreateInstance(__uuidof(AudioMediaSource)));
			__C(pSource->SetMediaType(NULL, g_nSampleRate, g_nChannelCount, g_nBitDepth));
			__C(pSource->put_Duration((DOUBLE) g_nDuration));
			pAudioMediaSource = pSource;
		}
		#pragma endregion 
		__D(pVideoMediaSource || pAudioMediaSource, E_UNNAMED);
		if(pVideoMediaSource && pAudioMediaSource)
		{
		    CComPtr<IMFCollection> pCollection;
		    __C(MFCreateCollection(&pCollection));
	        __C(pCollection->AddElement(pVideoMediaSource));
	        __C(pCollection->AddElement(pAudioMediaSource));
	        __C(MFCreateAggregateSource(pCollection, &pMediaSource));
		} else
			pMediaSource = pVideoMediaSource ? pVideoMediaSource : pAudioMediaSource;
		_A(pMediaSource);
		#pragma endregion 
		CPath sFilePath;
		{
			SYSTEMTIME Time;
			GetLocalTime(&Time);
			const CString sFileName = AtlFormatString(_T("%04d%02d%02d-%02d%02d%02d.mp4"), Time.wYear, Time.wMonth, Time.wDay, Time.wHour, Time.wMinute, Time.wSecond);
			sFilePath = Combine(GetPathDirectory(GetModulePath()), sFileName);
		}
		#pragma region Topology
		// NOTE: Creating Topologies https://msdn.microsoft.com/en-us/library/windows/desktop/ms702144
		//       Topology Node Attributes https://msdn.microsoft.com/en-us/library/windows/desktop/aa369728
		//       Tutorial: Encoding an MP4 File https://msdn.microsoft.com/en-us/library/ff819476
		MF::CTopology pTopology;
		//pTopology.Create();
		#pragma region Profile
		CComPtr<IMFTranscodeProfile> pTranscodeProfile;
		{
			__C(MFCreateTranscodeProfile(&pTranscodeProfile));
			#pragma region Video
			if(pVideoMediaSource)
			{
				MF::CAttributes pAttributes;
				pAttributes.Create(8);
				pAttributes[MF_MT_SUBTYPE] = 
					MFVideoFormat_H264;
					//MFVideoFormat_HEVC;
				pAttributes[MF_MT_AVG_BITRATE] = (UINT32) g_nVideoBitrate;
				pAttributes[MF_MT_FRAME_SIZE].SetSize(g_Extent.cx, g_Extent.cy);
				pAttributes[MF_MT_FRAME_RATE].SetRatio(g_nFrameRateNumerator, g_nFrameRateDenominator);
				__C(pTranscodeProfile->SetVideoAttributes(pAttributes));
				pAttributes.Trace();
			}
			#pragma endregion
			#pragma region Audio
			if(pAudioMediaSource)
			{
				// NOTE: The following audio attributes can be set: https://msdn.microsoft.com/en-us/library/windows/desktop/dd369143
				//   Audio Media Types 
				//   MF_TRANSCODE_DONOT_INSERT_ENCODER 
				//   MF_TRANSCODE_ENCODINGPROFILE 
				//   MF_TRANSCODE_QUALITYVSSPEED
				MF::CAttributes pAttributes;
				pAttributes.Create(8);
				pAttributes[MF_MT_SUBTYPE] = MFAudioFormat_AAC;
				pAttributes[MF_MT_AUDIO_SAMPLES_PER_SECOND] = (UINT32) g_nSampleRate;
				pAttributes[MF_MT_AUDIO_NUM_CHANNELS] = (UINT32) g_nChannelCount;
				pAttributes[MF_MT_AUDIO_BITS_PER_SAMPLE] = (UINT32) g_nBitDepth;
				pAttributes[MF_MT_AUDIO_AVG_BYTES_PER_SECOND] = (UINT32) g_nAudioBitrate;
				__C(pTranscodeProfile->SetAudioAttributes(pAttributes));
				pAttributes.Trace();
			}
			#pragma endregion
			MF::CAttributes pAttributes;
			pAttributes.Create(2);
			pAttributes[MF_TRANSCODE_CONTAINERTYPE] = 
				MFTranscodeContainerType_MPEG4;
				//MFTranscodeContainerType_FMPEG4;
			pAttributes[MF_TRANSCODE_TOPOLOGYMODE] = (UINT32) MF_TRANSCODE_TOPOLOGYMODE_HARDWARE_ALLOWED;
			__C(pTranscodeProfile->SetContainerAttributes(pAttributes));
		}
		#pragma endregion
		__C(MFCreateTranscodeTopology(pMediaSource, CT2CW((LPCTSTR) sFilePath), pTranscodeProfile, &pTopology.m_p));
		pTopology.Trace();
		#pragma endregion 
		#pragma region Session
		CComPtr<IMFMediaSession> pMediaSession;
		__C(MFCreateMediaSession(NULL, &pMediaSession));
		__C(pMediaSession->SetTopology(0, pTopology));
		for(BOOL bDone = FALSE; !bDone; )
		{
			MF::CMediaEvent pMediaEvent;
			__C(pMediaSession->GetEvent(0, &pMediaEvent));
			pMediaEvent.Trace();
			MediaEventType Type;
			__C(pMediaEvent->GetType(&Type));
			HRESULT nStatus;
			__C(pMediaEvent->GetStatus(&nStatus));
			switch(Type)
			{
			case MESessionTopologySet:
				{
					MF::CPropVariant vValue;
					if(SUCCEEDED(pMediaEvent->GetValue(&vValue)) && vValue.vt == VT_UNKNOWN)
					{
						MF::CTopology pTopology;
						pTopology.m_p = CComQIPtr<IMFTopology>(vValue.punkVal);
						pTopology.Trace();
					}
				}
				break;
			case MESessionTopologyStatus:
				{
					const MF_TOPOSTATUS TopoStatus = (MF_TOPOSTATUS) pMediaEvent.GetUINT32(MF_EVENT_TOPOLOGY_STATUS);
					_Z4(atlTraceGeneral, 4, _T("TopoStatus %s\n"), MF::FormatTopologyStatus(TopoStatus));
					switch(TopoStatus)
					{
					case MF_TOPOSTATUS_READY:
						{
							pTopology.Trace();
							MF::CPropVariant vStartPosition;
							//vStartPosition.vt = VT_I8;
							//vStartPosition.hVal.QuadPart = 2 * 1000 * 10000i64;
							__C(pMediaSession->Start(&GUID_NULL, &vStartPosition));
						}
						break;
					case MF_TOPOSTATUS_ENDED:
						break;
					}
				}
				break;
			case MESessionStarted:
				break;
			case MESessionEnded:
				__C(pMediaSession->Stop());
				break;
			case MESessionStopped:
				__C(pMediaSession->Close());
				break;
			case MESessionClosed:
				bDone = TRUE;
				break;
			}
			if(FAILED(nStatus))
				bDone = TRUE;
		}
		__C(pMediaSession->Shutdown());
		#pragma endregion 
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
