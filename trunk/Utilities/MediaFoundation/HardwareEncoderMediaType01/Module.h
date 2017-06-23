////////////////////////////////////////////////////////////
// Copyright (C) Roman Ryltsov, 2017
// Created by Roman Ryltsov roman@alax.info
//
// A permission to use the source code is granted as long as reference to 
// source website http://alax.info is retained.

#pragma once

#include "rodshow.h"
#include "romf.h"
#include "rod3d11.h"

////////////////////////////////////////////////////////////
// CModule

class CModule :
	public CAtlExeModuleT<CModule>
{
public:

public:
	static CEvent g_TerminationEvent;

public:
// CModule
	CModule()
	{
		AtlTraceSetDefaultSettings();
		_Z4_THIS();
		//_W(CExceptionFilter::Initialize());
	}
	~CModule()
	{
		_Z4_THIS();
		//CExceptionFilter::Terminate();
	}
	bool ParseCommandLine(LPCTSTR pszCommandLine, HRESULT* pnResult)
	{
		_A(pnResult);
		_ATLTRY
		{
			CCommandLineArguments Arguments(pszCommandLine);
			CCommandLineArguments::CArgument Argument;
			while(Arguments.Next(Argument))
			{
				__D(!Argument.m_bSwitch, E_UNNAMED);
				#pragma region help
				if(Argument.m_sValue.CompareNoCase(_T("help")) == 0)
				{
					_tprintf(
						_T("Syntax: %s argument [argument...]") _T("\n")
						_T("\n")
						_T("Arguments:") _T("\n")
						_T("\t") _T("help - displays syntax") _T("\n"),
						FindFileName(GetModulePath()));
					return false;
				} else
				#pragma endregion
					__C(E_UNNAMED);
			}
		}
		_ATLCATCH(Exception)
		{
			*pnResult = Exception;
			return false;
		}
		*pnResult = S_OK;
		return true;
	}
	HRESULT PreMessageLoop(INT nShowCommand)
	{
		const HRESULT nResult = __super::PreMessageLoop(nShowCommand);
		return SUCCEEDED(nResult) ? S_OK : nResult;
	}
	BOOL InternalHandlerRoutine(DWORD nType)
	{
		_W(g_TerminationEvent.Set());
		return TRUE;
	}
	static BOOL WINAPI HandlerRoutine(DWORD nType)
	{
		return static_cast<CModule*>(_pAtlModule)->InternalHandlerRoutine(nType);
	}
	BOOL ProcessNalUnits(const BYTE* pnData, SIZE_T nDataSize, LPCTSTR pszPrefix)
	{
		_A(pnData && nDataSize);
		CRoArrayT<SIZE_T> StartCodePositionArray;
		SIZE_T nPositionA = 0;
		for(; ; )
		{
			SIZE_T nPositionB = nPositionA;
			BOOL bFound = FALSE;
			for(; nPositionB + 3 + 1 <= nDataSize; nPositionB++)
			{
				if(pnData[nPositionB + 0] == 0x00 && pnData[nPositionB + 1] == 0x00 && pnData[nPositionB + 2] == 0x01)
				{
					bFound = TRUE;
					break;
				}
			}
			if(!bFound)
				break;
			nPositionA = nPositionB + 4;
			if(nPositionB > 0 && pnData[nPositionB - 1] == 0x00)
				nPositionB--;
			StartCodePositionArray.Add(nPositionB);
		}
		if(StartCodePositionArray.IsEmpty())
			return FALSE;
		for(SIZE_T nIndex = 0; nIndex < StartCodePositionArray.GetCount(); nIndex++)
		{
			const SIZE_T nPosition = StartCodePositionArray[nIndex];
			const UINT nType = ((pnData[nPosition + 2] == 0x01) ? pnData[nPosition + 3] : pnData[nPosition + 4]) & 0x1F;
			const SIZE_T nBoundaryPosition = (nIndex + 1 == StartCodePositionArray.GetCount()) ? nDataSize : StartCodePositionArray[nIndex + 1];
			static const SIZE_T g_nMaximalDataSize = 32;
			_tprintf(_T("%s NAL Unit Type %d, Size %d, Data %s%s\n"), 
				pszPrefix,
				nType,
				(INT) (nBoundaryPosition - nPosition),
				(LPCTSTR) AtlFormatData(pnData + nPosition, min(g_nMaximalDataSize, nBoundaryPosition - nPosition)),
				((nBoundaryPosition - nPosition) > g_nMaximalDataSize) ? _T("...") : _T(""));
		}
		return TRUE;
	}
	VOID ProcessTransform(ID3D11Device* pDevice, const CComPtr<IMFTransform>& pTransform)
	{
		_A(pTransform);
		MF::CAttributes pAttributes;
		__C(pTransform->GetAttributes(&pAttributes));
		pAttributes.Trace();
		pAttributes[MF_TRANSFORM_ASYNC_UNLOCK] = (UINT32) 1;
		if(pDevice)
		{
			MF::CDxgiDeviceManager pDxgiDeviceManager;
			pDxgiDeviceManager.Create();
			pDxgiDeviceManager.Reset(pDevice);
			__C(pTransform->ProcessMessage(MFT_MESSAGE_SET_D3D_MANAGER, (ULONG_PTR) (IMFDXGIDeviceManager*) pDxgiDeviceManager));
		}
		#pragma region Output Media Type
		// Video Media Types https://msdn.microsoft.com/en-us/library/windows/desktop/aa473818
		MF::CMediaType pOutputMediaType;
		pOutputMediaType.Create();
		pOutputMediaType[MF_MT_MAJOR_TYPE] = MFMediaType_Video;
		pOutputMediaType[MF_MT_SUBTYPE] = MFVideoFormat_H264;
		pOutputMediaType[MF_MT_FRAME_SIZE].SetSize(1280, 720);
		pOutputMediaType[MF_MT_PIXEL_ASPECT_RATIO].SetRatio(1, 1);
		pOutputMediaType[MF_MT_INTERLACE_MODE] = (UINT32) MFVideoInterlace_Progressive;
		pOutputMediaType[MF_MT_FRAME_RATE].SetRatio(60000, 1001);
		pOutputMediaType[MF_MT_AVG_BITRATE] = (UINT32) ((5 << 10) * 1000);
		pOutputMediaType.Trace();
		__C(pTransform->SetOutputType(0, pOutputMediaType, 0));
		#pragma endregion 
		#pragma region Available Input Media Type
		for(DWORD nTypeIndex = 0; ; nTypeIndex++)
		{
			MF::CMediaType pMediaType;
			if(FAILED(pTransform->GetInputAvailableType(0, nTypeIndex, &pMediaType)))
				break;
			pMediaType.Trace();
		}
		#pragma endregion 
		#pragma region Input Media Type
		// NOTE: Uncompressed Video Media Types https://msdn.microsoft.com/en-us/library/windows/desktop/ff485865
		MF::CMediaType pInputMediaType;
		pInputMediaType.Create();
		pInputMediaType[MF_MT_MAJOR_TYPE] = MFMediaType_Video;
		pInputMediaType[MF_MT_SUBTYPE] = MFVideoFormat_NV12;
		pInputMediaType[MF_MT_FRAME_SIZE] = pOutputMediaType.GetUINT64(MF_MT_FRAME_SIZE);
		pInputMediaType[MF_MT_PIXEL_ASPECT_RATIO] = pOutputMediaType.GetUINT64(MF_MT_PIXEL_ASPECT_RATIO);
		pInputMediaType[MF_MT_INTERLACE_MODE] = (UINT32) MFVideoInterlace_Progressive;
		pInputMediaType[MF_MT_FRAME_RATE] = pOutputMediaType.GetUINT64(MF_MT_FRAME_RATE);
		pInputMediaType.Trace();
		__C(pTransform->SetInputType(0, pInputMediaType, 0));
		#pragma endregion 
		#pragma region Actual Input Media Type
		MFT_INPUT_STREAM_INFO InputStreamInformation;
		__C(pTransform->GetInputStreamInfo(0, &InputStreamInformation));
		_Z3(atlTraceGeneral, 3, _T("Input Stream Information, hnsMaxLatency %s, dwFlags %s, cbSize %d, cbMaxLookahead %d, cbAlignment %d\n"), 
			MF::FormatNanoTime(InputStreamInformation.hnsMaxLatency),
			MF::FormatTransformInputStreamFlags(InputStreamInformation.dwFlags),
			InputStreamInformation.cbSize,
			InputStreamInformation.cbMaxLookahead,
			InputStreamInformation.cbAlignment,
			0);
		#pragma endregion 
		#pragma region Actual Output Media Type
		{
			MF::CMediaType pOutputMediaType;
			__C(pTransform->GetOutputCurrentType(0, &pOutputMediaType));
			pOutputMediaType.Trace();
			const MF_ATTRIBUTE_TYPE Type = pOutputMediaType.GetType(MF_MT_MPEG_SEQUENCE_HEADER);
			_tprintf(_T("MF_MT_MPEG_SEQUENCE_HEADER: %s\n"), (LPCTSTR) MF::FormatAttributeType(Type));
			if(Type == MF_ATTRIBUTE_BLOB)
			{
				CComHeapPtr<UINT8> pnData;
				UINT32 nDataSize;
				pOutputMediaType.GetBlob(MF_MT_MPEG_SEQUENCE_HEADER, pnData, nDataSize);
				ProcessNalUnits(pnData, nDataSize, _T("Media Type"));
			}
		}
		MFT_OUTPUT_STREAM_INFO OutputStreamInformation;
		__C(pTransform->GetOutputStreamInfo(0, &OutputStreamInformation));
		_A(OutputStreamInformation.dwFlags & (MFT_OUTPUT_STREAM_PROVIDES_SAMPLES | MFT_OUTPUT_STREAM_CAN_PROVIDE_SAMPLES));
		_Z3(atlTraceGeneral, 3, _T("Output Stream Information, dwFlags %s, cbSize %d, cbAlignment %d\n"), 
			MF::FormatTransformOutputStreamFlags(OutputStreamInformation.dwFlags),
			OutputStreamInformation.cbSize,
			OutputStreamInformation.cbAlignment,
			0);
		#pragma endregion 
		__C(pTransform->ProcessMessage(MFT_MESSAGE_NOTIFY_BEGIN_STREAMING, 0));
		__C(pTransform->ProcessMessage(MFT_MESSAGE_NOTIFY_START_OF_STREAM, 0));
		#if TRUE
			#pragma region Asynchronous Processing
			const CComQIPtr<IMFMediaEventGenerator> pMediaEventGenerator = pTransform;
			_A(pMediaEventGenerator);
			UINT nFrameIndex = 0;
			BOOL bComplete = FALSE;
			for(UINT nIteration = 0; !bComplete; nIteration++)
			{
				__D(nIteration < 256, E_UNNAMED);
				MF::CMediaEvent pMediaEvent;
				__C(pMediaEventGenerator->GetEvent(0, &pMediaEvent));
				pMediaEvent.Trace();
				switch(pMediaEvent.GetType())
				{
				#pragma region METransformNeedInput
				case METransformNeedInput:
					{
						MF::CSample pSample;
						pSample.Create();
						pSample[MFSampleExtension_Discontinuity] = (UINT32) (nFrameIndex == 0 ? 1 : 0);
						pSample[MFSampleExtension_CleanPoint] = (UINT32) 1;
						pSample->SetSampleTime(nFrameIndex * 20 * 10000i64);
						pSample->SetSampleDuration(20 * 10000i64);
						CComPtr<IMFMediaBuffer> pMediaBuffer;
						__C(MFCreateMemoryBuffer(1280 * 720 * 12 / 8, &pMediaBuffer));
						__C(pMediaBuffer->SetCurrentLength(1280 * 720 * 12 / 8));
						__C(pSample->AddBuffer(pMediaBuffer));
						pSample.Trace();
						const HRESULT nProcessInputResult = pTransform->ProcessInput(0, pSample, 0);
						_Z45_MFHRESULT(nProcessInputResult);
						__C(nProcessInputResult);
					}
					break;
				#pragma endregion
				#pragma region METransformHaveOutput
				case METransformHaveOutput:
					{
						_A(OutputStreamInformation.dwFlags & (MFT_OUTPUT_STREAM_PROVIDES_SAMPLES | MFT_OUTPUT_STREAM_CAN_PROVIDE_SAMPLES));
						MFT_OUTPUT_DATA_BUFFER Buffer = { 0 };
						DWORD nStatus;
						const HRESULT nProcessOutputResult = pTransform->ProcessOutput(0, 1, &Buffer, &nStatus);
						_Z45_MFHRESULT(nProcessOutputResult);
						_Z3(atlTraceGeneral, 3, _T("Output Data Buffer, dwStatus %s, pSample 0x%p, pEvents 0x%p\n"), MF::FormatTransformOutputDataBufferFlags(Buffer.dwStatus), Buffer.pSample, Buffer.pEvents);
						// NOTE: IMFTransform::ProcessOutput method, Stream Changes https://msdn.microsoft.com/en-us/library/windows/desktop/ms704014#Stream_Changes
						if(nProcessOutputResult == MF_E_TRANSFORM_STREAM_CHANGE)
						{
							__D(Buffer.dwStatus & MFT_OUTPUT_DATA_BUFFER_FORMAT_CHANGE, nProcessOutputResult);
							_A(!Buffer.pSample && !Buffer.pEvents);
							{
								MF::CMediaType pMediaType;
								__C(pTransform->GetOutputCurrentType(0, &pMediaType));
								pMediaType.Trace();
							}
							MF::CMediaType pOutputMediaType;
							#pragma region Available Output Media Type
							for(DWORD nTypeIndex = 0; ; nTypeIndex++)
							{
								MF::CMediaType pMediaType;
								if(FAILED(pTransform->GetOutputAvailableType(0, nTypeIndex, &pMediaType)))
									break;
								pMediaType.Trace();
								if(!nTypeIndex)
									pOutputMediaType = pMediaType;
							}
							#pragma endregion 
							__D(pOutputMediaType, nProcessOutputResult);
							__C(pTransform->SetOutputType(0, pOutputMediaType, 0));
							break;
						}
						__C(nProcessOutputResult);
						_A(Buffer.dwStatus == 0);
						_A(!Buffer.pEvents);
						MF::CSample pSample;
						pSample.m_p.Attach(Buffer.pSample);
						pSample.Trace();
						CComPtr<IMFMediaBuffer> pMediaBuffer;
						__C(pSample->ConvertToContiguousBuffer(&pMediaBuffer));
						MF::CSample::CMediaBufferLock Lock(pMediaBuffer);
						_Z4(atlTraceGeneral, 4, _T("Lock.m_pnData %s, Lock.m_nDataSize %d\n"), AtlFormatData(Lock.m_pnData, min(32, Lock.m_nDataSize)), Lock.m_nDataSize);
						ProcessNalUnits(Lock.m_pnData, Lock.m_nDataSize, _T("Output"));
						bComplete = TRUE;
					}
					break;
				#pragma endregion
				default:
					__C(E_UNNAMED);
				}
			}
			#pragma endregion
		#else
			#pragma region Synchronous Processing
			UINT nFrameIndex = 0;
			for(; ; )
			{
				DWORD nInputStatusFlags;
				__C(pTransform->GetInputStatus(0, &nInputStatusFlags));
				_Z4(atlTraceGeneral, 4, _T("nInputStatusFlags %s\n"), MF::FormatTransformProcessInputStatusFlags(nInputStatusFlags));
				if(nInputStatusFlags & MFT_INPUT_STATUS_ACCEPT_DATA)
				{
					MF::CSample pSample;
					pSample.Create();
					pSample[MFSampleExtension_Discontinuity] = (UINT32) (nFrameIndex == 0 ? 1 : 0);
					pSample[MFSampleExtension_CleanPoint] = (UINT32) 1;
					pSample->SetSampleTime(nFrameIndex * 20 * 10000i64);
					pSample->SetSampleDuration(20 * 10000i64);
					CComPtr<IMFMediaBuffer> pMediaBuffer;
					__C(MFCreateMemoryBuffer(1280 * 720 * 12 / 8, &pMediaBuffer));
					__C(pMediaBuffer->SetCurrentLength(1280 * 720 * 12 / 8));
					__C(pSample->AddBuffer(pMediaBuffer));
					pSample.Trace();
					const HRESULT nProcessInputResult = pTransform->ProcessInput(0, pSample, 0);
					if(nProcessInputResult != MF_E_NOTACCEPTING)
					{
						__C(nProcessInputResult);
						nFrameIndex++;
						continue;
					}
				}
				_A(OutputStreamInformation.dwFlags & (MFT_OUTPUT_STREAM_PROVIDES_SAMPLES | MFT_OUTPUT_STREAM_CAN_PROVIDE_SAMPLES));
				MFT_OUTPUT_DATA_BUFFER Buffer = { 0 };
				DWORD nStatus;
				__C(pTransform->ProcessOutput(0, 1, &Buffer, &nStatus));
				MF::CSample pSample;
				pSample.m_p.Attach(Buffer.pSample);
				pSample.Trace();
				CComPtr<IMFMediaBuffer> pMediaBuffer;
				__C(pSample->ConvertToContiguousBuffer(&pMediaBuffer));
				MF::CSample::CMediaBufferLock Lock(pMediaBuffer);
				_Z4(atlTraceGeneral, 4, _T("Lock.m_pnData %s, Lock.m_nDataSize %d\n"), AtlFormatData(Lock.m_pnData, min(24, Lock.m_nDataSize)), Lock.m_nDataSize);
				// TODO: ...
			}
			#pragma endregion
		#endif
	}
	VOID RunMessageLoop()
	{
		MF::CStartup Startup;
		MFT_REGISTER_TYPE_INFO Information = { MFMediaType_Video, MFVideoFormat_H264 };
		CComHeapPtr<IMFActivate*> ppActivates;
		UINT32 nActivateCount = 0;
		__C(MFTEnumEx(MFT_CATEGORY_VIDEO_ENCODER, MFT_ENUM_FLAG_HARDWARE, NULL, &Information, &ppActivates, &nActivateCount));
		if(!nActivateCount)
			return;
		MF::CActivateArray ActivateArray;
		ActivateArray.SetCount(nActivateCount);
		memcpy(ActivateArray.GetData(), ppActivates, nActivateCount * sizeof *ppActivates);
		#pragma region DXGI
		DXGI::CFactory2 pFactory2;
		CRoArrayT<DXGI::CAdapter1> AdapterArray;
		{
			UINT nFlags = 0;
			#if defined(_DEBUG)
				nFlags |= DXGI_CREATE_FACTORY_DEBUG;
			#endif // defined(_DEBUG)
			__C(CreateDXGIFactory2(nFlags, __uuidof(IDXGIFactory2), (VOID**) &pFactory2.m_p));
			for(UINT nAdapterIndex = 0; ; nAdapterIndex++)
			{
				DXGI::CAdapter1 pAdapter1;
				const HRESULT nResult = pFactory2->EnumAdapters1(nAdapterIndex, &pAdapter1.m_p);
				_Z45_MFHRESULT(nResult);
				if(FAILED(nResult))
					break;
				pAdapter1.Trace();
				//DXGI_ADAPTER_DESC1 Description;
				//__C(pAdapter1->GetDesc1(&Description));
				//if(Description.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
				//	continue;
				AdapterArray.Add(pAdapter1);
			}
		}
		#pragma endregion 
		for(auto&& pActivate: ActivateArray)
		{
			pActivate.Trace();
			//if(pActivate.GetString(MFT_FRIENDLY_NAME_Attribute).Find(L"Quick Sync Video H.264 Encoder MFT") < 0)
			//	continue;
			_tprintf(_T("Friendly Name: %ls\n"), (LPCWSTR) pActivate.GetString(MFT_FRIENDLY_NAME_Attribute));
			_tprintf(_T("\n"));
			const CLSID ClassIdentifier = pActivate.GetGUID(MFT_TRANSFORM_CLSID_Attribute);
			for(SIZE_T nIndex = 0; ; nIndex++)
			{
				_ATLTRY
				{
					CComPtr<ID3D11Device> pDevice;
					CComPtr<ID3D11DeviceContext> pDeviceContext;
					if(nIndex >= 1)
					{
						if(nIndex - 1 >= AdapterArray.GetCount())
							break;
						DXGI::CAdapter1& pAdapter1 = AdapterArray[nIndex - 1];
						DXGI_ADAPTER_DESC1 Description;
						__C(pAdapter1->GetDesc1(&Description));
						//if(CStringW(Description.Description).Find(L" Intel(R) HD Graphics") < 0)
						//	continue;
						_tprintf(_T("Adapter Description: %ls\n"), Description.Description);
						_tprintf(_T("\n"));
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
						__C(D3D11CreateDevice(pAdapter1, D3D_DRIVER_TYPE_UNKNOWN, NULL, nFlags, g_pFeatureLevels, DIM(g_pFeatureLevels), D3D11_SDK_VERSION, &pDevice, &FeatureLevel, &pDeviceContext));
					}
					_ATLTRY
					{
						ProcessTransform(pDevice, pActivate.Activate<IMFTransform>());
					}
					_ATLCATCH(Exception)
					{
						_Z_ATLEXCEPTION(Exception);
						_tprintf(_T("Exception: %s\n"), (LPCTSTR) MF::FormatResult(Exception, _T("Error 0x%08X")));
					}
					_tprintf(_T("\n"));
					_ATLTRY
					{
						CComPtr<IMFTransform> pTransform;
						__C(pTransform.CoCreateInstance(ClassIdentifier));
						ProcessTransform(pDevice, pTransform);
					}
					_ATLCATCH(Exception)
					{
						_Z_ATLEXCEPTION(Exception);
						_tprintf(_T("Exception: %s\n"), (LPCTSTR) MF::FormatResult(Exception, _T("Error 0x%08X")));
					}
					_tprintf(_T("\n"));
				}
				_ATLCATCHALL()
				{
					_Z_EXCEPTION();
				}
			}
		}
	}
};

__declspec(selectany) CEvent CModule::g_TerminationEvent;

