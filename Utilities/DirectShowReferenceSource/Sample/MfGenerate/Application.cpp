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
		CComPtr<IMFSourceResolver> pSourceResolver;
		__C(MFCreateSourceResolver(&pSourceResolver));
		#pragma region Media Source
		CComQIPtr<IMFMediaSource> pMediaSource;

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

		//const SIZE g_Extent = { 640, 360 };
		//const LONG g_nFrameRateNumerator = 30000;
		//const LONG g_nFrameRateDenominator = 1001;
		//const LONG g_nDuration = 1 * 60; // 1 minutes
		//const LONG g_nBitrate = (2 << 10) * 1000; // 2 MBps

		//const SIZE g_Extent = { 720, 480 };
		//const LONG g_nFrameRateNumerator = 90; //30 * 1000;
		//const LONG g_nFrameRateDenominator = 1; //1001;
		//const LONG g_nDuration = 60; //5 * 60; // 5 minutes
		//const LONG g_nBitrate = (2 << 10) * 1000; // 2 MBps

		//const SIZE g_Extent = { 1280, 720 };
		//const LONG g_nFrameRateNumerator = 60 * 1000;
		//const LONG g_nFrameRateDenominator = 1000;
		//const LONG g_nDuration = 5 * 60; // 5 minutes
		//const LONG g_nBitrate = (5 << 10) * 1000; // 5 MBps

		const SIZE g_Extent = { 1920, 1080 };
		const LONG g_nFrameRateNumerator = 50 * 1000; // frames/second
		const LONG g_nFrameRateDenominator = 1000;
		const LONG g_nDuration = 1 * 60; // minutes
		const LONG g_nBitrate = (10 * 1000) * 1000; // 10 MBps

		//const SIZE g_Extent = { 4096, 2304 };
		//const LONG g_nFrameRateNumerator = 50;
		//const LONG g_nFrameRateDenominator = 1;
		//const LONG g_nDuration = 5 * 60; // 5 minutes
		//const LONG g_nBitrate = (2 << 10) * 1000; // 2 MBps

		#pragma region DXGI Device Manager
		static SIZE_T g_nDxgiAdapterIndex = 0;
		MF::CDxgiDeviceManager pDxgiDeviceManager;
		{
			#pragma region DXGI Adapter
			DXGI::CFactory2 pFactory2;
			pFactory2.DebugCreate();
			CRoArrayT<DXGI::CAdapter1> AdapterArray;
			_A(pFactory2.EnumerateAdapters(AdapterArray) == 3);
			DXGI::CAdapter1& pAdapter1 = AdapterArray[g_nDxgiAdapterIndex];
			#pragma region D3D11 Device
			CComPtr<ID3D11Device> pDevice;
			UINT nFlags = D3D11_CREATE_DEVICE_VIDEO_SUPPORT;
			#if defined(_DEBUG)
				nFlags |= D3D11_CREATE_DEVICE_DEBUG;
			#endif // defined(_DEBUG)
			static const D3D_FEATURE_LEVEL g_pFeatureLevels[] = 
			{
				D3D_FEATURE_LEVEL_12_1,
				D3D_FEATURE_LEVEL_12_0,
				D3D_FEATURE_LEVEL_11_1,
				D3D_FEATURE_LEVEL_11_0,
				D3D_FEATURE_LEVEL_10_1,
				D3D_FEATURE_LEVEL_10_0,
				D3D_FEATURE_LEVEL_9_3,
				D3D_FEATURE_LEVEL_9_2,
				D3D_FEATURE_LEVEL_9_1,
			};
			D3D_FEATURE_LEVEL FeatureLevel;
			CComPtr<ID3D11DeviceContext> pDeviceContext;
			// SUGG: Reuse CVideoInput's CreateDevice doing D3D11CreateDevice
			__C(D3D11CreateDevice(pAdapter1, D3D_DRIVER_TYPE_UNKNOWN, NULL, nFlags, g_pFeatureLevels, DIM(g_pFeatureLevels), D3D11_SDK_VERSION, &pDevice, &FeatureLevel, &pDeviceContext));
			const CComQIPtr<ID3D11Multithread> pMultithread = pDevice;
			__D(pMultithread, E_NOINTERFACE);
			pMultithread->SetMultithreadProtected(TRUE);
			#pragma endregion 
			#pragma endregion 
			pDxgiDeviceManager.Create();
			pDxgiDeviceManager.Reset(pDevice);
		}
		#pragma endregion 

		{
			using namespace AlaxInfoDirectShowReferenceSource;
			CComPtr<IVideoMediaSource> pVideoMediaSource;
			__C(pVideoMediaSource.CoCreateInstance(__uuidof(VideoMediaSource)));
			__C(pVideoMediaSource->SetMediaType(g_Extent.cx, g_Extent.cy, CComVariant(_PersistHelper::StringFromIdentifier(MEDIASUBTYPE_RGB32))));
			//__C(pVideoMediaSource->SetMediaTypeAspectRatio(...));
			__C(pVideoMediaSource->SetMediaTypeRate(g_nFrameRateNumerator, g_nFrameRateDenominator));
			__C(pVideoMediaSource->put_Duration((DOUBLE) g_nDuration));
			pMediaSource = pVideoMediaSource;
		}
		#pragma endregion 
		CComPtr<IMFSourceReader> pSourceReader;
		{
			MF::CAttributes pAttributes;
			if(pDxgiDeviceManager)
			{
				pAttributes.Create(4);
				pAttributes[MF_READWRITE_D3D_OPTIONAL] = (UINT32) 0;
				pAttributes[MF_SOURCE_READER_D3D_MANAGER] = (IMFDXGIDeviceManager*) pDxgiDeviceManager;
			}
			__C(MFCreateSourceReaderFromMediaSource(pMediaSource, pAttributes, &pSourceReader));
		}
		MF::CMediaType pMediaType;
		__C(pSourceReader->GetCurrentMediaType(MF_SOURCE_READER_FIRST_VIDEO_STREAM, &pMediaType));
		pMediaType.Trace();
		SYSTEMTIME Time;
		GetLocalTime(&Time);
		const CString sFileName = AtlFormatString(_T("%04d%02d%02d-%02d%02d%02d.mp4"), Time.wYear, Time.wMonth, Time.wDay, Time.wHour, Time.wMinute, Time.wSecond);
		CComPtr<IMFSinkWriter> pSinkWriter;
		{
			MF::CAttributes pAttributes;
			if(pDxgiDeviceManager)
			{
				pAttributes.Create(4);
				pAttributes[MF_READWRITE_D3D_OPTIONAL] = (UINT32) 0;
				pAttributes[MF_SINK_WRITER_D3D_MANAGER] = (IMFDXGIDeviceManager*) pDxgiDeviceManager;
			}
			__C(MFCreateSinkWriterFromURL(Combine(GetPathDirectory(GetModulePath()), sFileName), NULL, pAttributes, &pSinkWriter));
		}
		MF::CMediaType pWriterMediaType;
		pWriterMediaType.Create();
		// NOTE: H.264 Video Encoder https://msdn.microsoft.com/en-us/library/windows/desktop/dd797816
		pWriterMediaType[MF_MT_MAJOR_TYPE] = MFMediaType_Video;
		pWriterMediaType[MF_MT_SUBTYPE] = MFVideoFormat_H264;
		pWriterMediaType.CopyFrom(pMediaType, MF_MT_FRAME_RATE);
		pWriterMediaType.CopyFrom(pMediaType, MF_MT_FRAME_SIZE);
		pWriterMediaType.CopyFrom(pMediaType, MF_MT_INTERLACE_MODE);
		pWriterMediaType.CopyFrom(pMediaType, MF_MT_PIXEL_ASPECT_RATIO);
		pWriterMediaType[MF_MT_AVG_BITRATE] = (UINT32) g_nBitrate;
		//pWriterMediaType[MF_MT_MPEG2_PROFILE] = (UINT32) eAVEncH264VProfile_High;
		pWriterMediaType.Trace();
		DWORD nWriterStreamIndex;
		__C(pSinkWriter->AddStream(pWriterMediaType, &nWriterStreamIndex));
		// NOTE: Sink Writer Attributes https://msdn.microsoft.com/en-us/library/windows/desktop/dd389284

		//class __declspec(uuid("4E498B6F-7DCA-403E-A523-912A73943341")) NvEncoderTransform;
		//MFT_REGISTER_TYPE_INFO pInputTypeInformation[] = { { MFMediaType_Video, MFVideoFormat_ARGB32 } };
		//MFT_REGISTER_TYPE_INFO pOutputTypeInformation[] = { { MFMediaType_Video, MFVideoFormat_H264 } };
		//__C(MFTRegisterLocalByCLSID(__uuidof(NvEncoderTransform), MFT_CATEGORY_VIDEO_ENCODER, L"Rainway H.264 Encoder for NVIDIA HW", MFT_ENUM_FLAG_ASYNCMFT, DIM(pInputTypeInformation), pInputTypeInformation, DIM(pOutputTypeInformation), pOutputTypeInformation));
		{
			MF::CAttributes pAttributes;
			pAttributes.Create(10);
			pAttributes[MF_READWRITE_ENABLE_HARDWARE_TRANSFORMS] = (UINT32) 1;
			__C(pSinkWriter->SetInputMediaType(nWriterStreamIndex, pMediaType, pAttributes));
		}
		MF::CSinkWriterHelper::TraceTransformsT<MF::CSinkWriterHelper::CVideoTraceTraits>(pSinkWriter);

		CRoArrayT<CComPtr<IMFTransform>> TransformArray;
		MF::CSinkWriterHelper::GetTransforms(pSinkWriter, nWriterStreamIndex, TransformArray);
		_A(!TransformArray.IsEmpty());
		MF::CCodecApi pCodecApi(TransformArray[TransformArray.GetCount() - 1]);
		pCodecApi[CODECAPI_AVEncCommonRateControlMode] = (UINT32) eAVEncCommonRateControlMode_CBR;
		pCodecApi[CODECAPI_AVEncCommonMeanBitRate] = (UINT32) g_nBitrate;
		pCodecApi[CODECAPI_AVEncMPVGOPSize] = (UINT32) 1;
		//pCodecApi[CODECAPI_AVEncMPVDefaultBPictureCount] = (UINT32) 0;

		const ULONG nTimeA = GetTickCount();
		__C(pSinkWriter->BeginWriting());
		for(; ; )
		{
			DWORD nStreamIndex, nStreamFlags;
			LONGLONG nTime;
			MF::CSample pSample;
			__C(pSourceReader->ReadSample(MF_SOURCE_READER_FIRST_VIDEO_STREAM, 0, &nStreamIndex, &nStreamFlags, &nTime, &pSample));
			_Z4(atlTraceGeneral, 4, _T("nStreamIndex %d, nStreamFlags %s, nTime %s, pSample 0x%p\n"), nStreamIndex, MF::FormatSourceReaderStreamFlags(nStreamFlags), MF::FormatNanoTime(nTime), pSample);
			if(pSample)
			{
				pSample.Trace();
				#pragma region Re-Configuration
				#if defined(_DEBUG)
					static INT g_nState = 0;
					if(!g_nState && pSample.GetTime() >= 30000 * 10000i64)
					{
						g_nState = 1;
						const CComQIPtr<IMFSinkWriterEncoderConfig> pSinkWriterEncoderConfig = pSinkWriter;
						__D(pSinkWriterEncoderConfig, E_NOINTERFACE);
						MF::CAttributes pAttributes;
						pAttributes.Create(4);
						//pAttributes[CODECAPI_AVEncCommonRateControlMode] = (UINT32) eAVEncCommonRateControlMode_CBR;
						pAttributes[CODECAPI_AVEncCommonMeanBitRate] = (UINT32) g_nBitrate / 4;
						// NOTE: MF_SOURCE_READER_FIRST_VIDEO_STREAM results in MF_E_INVALIDSTREAMNUMBER
						__C(pSinkWriterEncoderConfig->PlaceEncodingParameters(0, pAttributes));
						// SUGG: Check IMFSinkWriterEncoderConfig::SetTargetMediaType as well
					}
				#endif // defined(_DEBUG)
				#pragma endregion 
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

