// NOTE: https://stackoverflow.com/questions/48207677/dxgi-1-5-duplicateoutput1-fails-with-dxgi-error-unsupported-0x887a0004

#include <winsdkver.h>
#include <sdkddkver.h>
#include <stdio.h>
#include <tchar.h>
#include <dxgi1_5.h>
#include <d3d11.h>
#include <atlbase.h>
#include <atlcom.h>

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")

VOID Check(INT nLine, HRESULT nResult)
{
	if(SUCCEEDED(nResult))
		return;
	_tprintf(_T("Failure 0x%08X in line %d\n"), nResult, nLine);
	AtlThrow(nResult);
}

#define __C(x)	Check(__LINE__, x)

int main()
{
	//CoInitializeEx(NULL, COINITBASE_MULTITHREADED);
	CComPtr<IDXGIFactory2> pFactory2;
    CComPtr<IDXGIAdapter1> pAdapter1;
#if 1
	__C(CreateDXGIFactory2(0, __uuidof(IDXGIFactory2), (VOID**) &pFactory2));
	__C(pFactory2->EnumAdapters1(0, &pAdapter1));
#endif
    CComPtr<ID3D11Device> pDevice;
    static const D3D_FEATURE_LEVEL g_pFeatureLevels[] = 
	{ 
		D3D_FEATURE_LEVEL_12_1,
		D3D_FEATURE_LEVEL_12_0,
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
	};
	D3D_FEATURE_LEVEL FeatureLevel;
	CComPtr<ID3D11DeviceContext> pDeviceContext;
    D3D11CreateDevice(pAdapter1, pAdapter1 ? D3D_DRIVER_TYPE_UNKNOWN : D3D_DRIVER_TYPE_HARDWARE, NULL, 0, g_pFeatureLevels, ARRAYSIZE(g_pFeatureLevels), D3D11_SDK_VERSION, &pDevice, &FeatureLevel, &pDeviceContext);
	_tprintf(_T("FeatureLevel 0x%04X\n"), FeatureLevel);
    const CComQIPtr<IDXGIDevice> pDxgiDevice = pDevice;
    CComPtr<IDXGIAdapter> pAdapter = pAdapter1;
	if(!pAdapter1)
		__C(pDxgiDevice->GetAdapter(&pAdapter));
	DXGI_ADAPTER_DESC AdapterDescription;
	__C(pAdapter->GetDesc(&AdapterDescription));
	_tprintf(_T("AdapterDescription.Description \"%ls\"\n"), AdapterDescription.Description);
    CComPtr<IDXGIOutput> pOutput;
    __C(pAdapter->EnumOutputs(0, &pOutput));
    CComPtr<IDXGIOutputDuplication> pOutputDuplication;
//    const CComQIPtr<IDXGIOutput5> pOutput5 = pOutput;
//    const DXGI_FORMAT formats[] = { DXGI_FORMAT_B8G8R8A8_UNORM };
//    const HRESULT nDuplicateOutput1Result = pOutput5->DuplicateOutput1(pDevice, 0, ARRAYSIZE(formats), formats, &pOutputDuplication); // 0x887A0004?
//	_tprintf(_T("nDuplicateOutput1Result 0x%08X\n"), nDuplicateOutput1Result);
//	if(FAILED(nDuplicateOutput1Result))
//	{
//		const HRESULT nDuplicateOutputResult = pOutput5->DuplicateOutput(pDevice, &pOutputDuplication);
//		_tprintf(_T("nDuplicateOutputResult 0x%08X\n"), nDuplicateOutputResult);
//		if(FAILED(nDuplicateOutputResult))
		{
		    const CComQIPtr<IDXGIOutput1> pOutput1 = pOutput;
			const HRESULT nDuplicateOutputResult = pOutput1->DuplicateOutput(pDevice, &pOutputDuplication);
			_tprintf(_T("nDuplicateOutputResult 0x%08X\n"), nDuplicateOutputResult);
		}
//	}
	if(pOutputDuplication)
	{
		DXGI_OUTDUPL_DESC OutputDuplicationDescription;
		pOutputDuplication->GetDesc(&OutputDuplicationDescription);
	}
    return 0;
}

