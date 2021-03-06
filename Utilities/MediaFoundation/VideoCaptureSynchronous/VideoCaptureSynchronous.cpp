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

#define __C ATLENSURE_SUCCEEDED
#define __D ATLENSURE_THROW

static UINT32 g_nIndex = 0;

int main()
{
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
		CComPtr<IMFSourceReader> pSourceReader;
		__C(MFCreateSourceReaderFromMediaSource(pMediaSource, NULL, &pSourceReader));
		LONGLONG nBaseTime = 0;
		for(; ; )
		{
			DWORD nStreamIndex;
			DWORD nStreamFlags;
			LONGLONG nTime;
			CComPtr<IMFSample> pSample;
			__C(pSourceReader->ReadSample(MF_SOURCE_READER_ANY_STREAM, 0, &nStreamIndex, &nStreamFlags, &nTime, &pSample));
			nTime -= nBaseTime;
			_tprintf(_T("nStreamIndex %d, nStreamFlags 0x%X, nTime %.3f, pSample 0x%p\n"), nStreamIndex, nStreamFlags, nTime / 1E7, (IMFSample*) pSample);
			if(nStreamIndex == 0 && (nStreamFlags & MF_SOURCE_READERF_STREAMTICK))
			{
				ATLASSERT(!pSample);
				nBaseTime = nTime;
				continue;
			}
		}
	}
	__C(MFShutdown());
    return 0;
}

