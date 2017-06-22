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
		__C(pTransform->SetInputType(0, pInputMediaType, 0));
		#pragma endregion 
		#pragma region Actual Input Media Type
		MFT_INPUT_STREAM_INFO InputStreamInformation;
		__C(pTransform->GetInputStreamInfo(0, &InputStreamInformation));
		#pragma endregion 
		#pragma region Actual Output Media Type
		{
			MF::CMediaType pOutputMediaType;
			__C(pTransform->GetOutputCurrentType(0, &pOutputMediaType));
			pOutputMediaType.Trace();
			_tprintf(_T("MF_MT_MPEG_SEQUENCE_HEADER: %d\n"), pOutputMediaType.GetType(MF_MT_MPEG_SEQUENCE_HEADER));
		}
		MFT_OUTPUT_STREAM_INFO OutputStreamInformation;
		__C(pTransform->GetOutputStreamInfo(0, &OutputStreamInformation));
		_A(OutputStreamInformation.dwFlags & (MFT_OUTPUT_STREAM_PROVIDES_SAMPLES | MFT_OUTPUT_STREAM_CAN_PROVIDE_SAMPLES));
		#pragma endregion 
		__C(pTransform->ProcessMessage(MFT_MESSAGE_NOTIFY_BEGIN_STREAMING, 0));
		__C(pTransform->ProcessMessage(MFT_MESSAGE_NOTIFY_START_OF_STREAM, 0));
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

