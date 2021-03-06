#include <winsdkver.h>
#include <sdkddkver.h>
#include <stdio.h>
#include <tchar.h>
#include <mfapi.h>
#include <mfidl.h>
#include <mfreadwrite.h>
#include <atlbase.h>
#include <atlcom.h>

#pragma comment(lib, "mfplat.lib")
#pragma comment(lib, "mf.lib")
#pragma comment(lib, "mfreadwrite.lib")

#define _A	ATLASSERT
#define __C ATLENSURE_SUCCEEDED
#define __D ATLENSURE_THROW

static UINT32 g_nIndex = 0;

class CModule :
	public CComModule
{
};

class ATL_NO_VTABLE CCallback :
	public CComObjectRootEx<CComMultiThreadModelNoCS>,
	public IMFSourceReaderCallback
{
public:

BEGIN_COM_MAP(CCallback)
	COM_INTERFACE_ENTRY(IMFSourceReaderCallback)
END_COM_MAP()

private:
	CComPtr<IMFSourceReader> m_pSourceReader;
	LONGLONG m_nBaseTime;

public:
// CCallback
	CCallback()
	{
	}
	VOID Initialize(IMFSourceReader* pSourceReader)
	{
		_A(!m_pSourceReader && pSourceReader);
		m_pSourceReader = pSourceReader;
		m_nBaseTime = 0;
	}
	VOID ReadSample()
	{
		_A(m_pSourceReader);
		__C(m_pSourceReader->ReadSample(MF_SOURCE_READER_ANY_STREAM, 0, NULL, NULL, NULL, NULL));
	}

// IMFSourceReaderCallback
	STDMETHOD(OnReadSample)(HRESULT nStatus, DWORD nStreamIndex, DWORD nStreamFlags, LONGLONG nTime, IMFSample* pSample) override
	{
		ATLTRACE(atlTraceCOM, 4, _T("nStatus 0x%08X, nStreamIndex %d, nStreamFlags 0x%X, nTime %I64d, pSample 0x%p\n"), nStatus, nStreamIndex, nStreamFlags, nTime, pSample);
		nTime -= m_nBaseTime;
		_tprintf(_T("nStatus 0x%08X, nStreamIndex %d, nStreamFlags 0x%X, nTime %.3f, pSample 0x%p\n"), nStatus, nStreamIndex, nStreamFlags, nTime / 1E7, (IMFSample*) pSample);
		if(nStreamIndex == 0 && (nStreamFlags & MF_SOURCE_READERF_STREAMTICK))
		{
			_A(!pSample);
			m_nBaseTime = nTime;
		}
		ReadSample();
		return S_OK;
	}
	STDMETHOD(OnFlush)(DWORD nStreamIndex) override
	{
		ATLTRACE(atlTraceCOM, 4, _T("nStreamIndex %d\n"), nStreamIndex);
		return S_OK;
	}
	STDMETHOD(OnEvent)(DWORD nStreamIndex, IMFMediaEvent* pMediaEvent) override
	{
		ATLTRACE(atlTraceCOM, 4, _T("nStreamIndex %d, pMediaEvent 0x%p\n"), nStreamIndex, pMediaEvent);
		return S_OK;
	}
};

int main()
{
	CModule Module;
	__C(MFStartup(MF_VERSION));
	{
		CComPtr<IMFMediaSource> pMediaSource;
		{
			CComPtr<IMFAttributes> pAttributes;
			__C(MFCreateAttributes(&pAttributes, 1));
			__C(pAttributes->SetGUID(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE, MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID));
			CComHeapPtr<IMFActivate*> ppActivates;
			UINT32 nActivateCount = 0;
			__C(MFEnumDeviceSources(pAttributes, &ppActivates, &nActivateCount));
			__D(g_nIndex < nActivateCount, E_INVALIDARG);
			const CComPtr<IMFActivate> pActivate = ppActivates[g_nIndex];
			for(UINT32 nIndex = 0; nIndex < nActivateCount; nIndex++)
				reinterpret_cast<CComPtr<IMFActivate>&>(ppActivates[nIndex]).Release();
			__C(pActivate->ActivateObject(__uuidof(IMFMediaSource), (VOID**) &pMediaSource));
			CComHeapPtr<WCHAR> pszFriendlyName;
			__C(pActivate->GetAllocatedString(MF_DEVSOURCE_ATTRIBUTE_FRIENDLY_NAME, &pszFriendlyName, NULL));
			_tprintf(_T("Friendly Name: %ls\n"), (LPCWSTR) pszFriendlyName);
		}
		CComObject<CCallback>* pCallback;
		__C(CComObject<CCallback>::CreateInstance(&pCallback));
		_A(pCallback->m_dwRef == 0);
		CComPtr<IMFAttributes> pAttributes;
		__C(MFCreateAttributes(&pAttributes, 1));
		__C(pAttributes->SetUnknown(MF_SOURCE_READER_ASYNC_CALLBACK, pCallback));
		CComPtr<IMFSourceReader> pSourceReader;
		__C(MFCreateSourceReaderFromMediaSource(pMediaSource, pAttributes, &pSourceReader));
		pCallback->Initialize(pSourceReader);
		pCallback->ReadSample();
		for(; ; )
			SwitchToThread();
	}
	__C(MFShutdown());
    return 0;
}

