#include <winsdkver.h>
#include <sdkddkver.h>
#include <mfapi.h>
#include <mftransform.h>
#include <stdio.h>
#include <tchar.h>
#include <atlbase.h>
#include <atlcom.h>

#pragma comment(lib, "mfuuid.lib")
#pragma comment(lib, "mfplat.lib")

#include <dxgi1_3.h>
#include <d3d11.h>

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")

//#define EASYHOOK
#define MINHOOK

typedef HRESULT (WINAPI *D3D11CREATEDEVICE)(_In_opt_ IDXGIAdapter* pAdapter, D3D_DRIVER_TYPE DriverType, HMODULE Software, UINT Flags, _In_reads_opt_( FeatureLevels ) CONST D3D_FEATURE_LEVEL* pFeatureLevels, UINT FeatureLevels, UINT SDKVersion, _COM_Outptr_opt_ ID3D11Device** ppDevice, _Out_opt_ D3D_FEATURE_LEVEL* pFeatureLevel, _COM_Outptr_opt_ ID3D11DeviceContext** ppImmediateContext);

#if defined(EASYHOOK)

#include <easyhook.h>

#if defined(_WIN64)
	#pragma comment(lib, "EasyHook64.lib")
#else
	#pragma comment(lib, "EasyHook32.lib")
#endif

#endif // defined(EASYHOOK)

#if defined(MINHOOK)

#include <minhook.h>

#pragma comment(lib, "libMinHook-x64-v141-mdd.lib")

D3D11CREATEDEVICE g_pD3D11CreateDevice = NULL;

#endif // defined(MINHOOK)

HRESULT WINAPI Hook_D3D11CreateDevice(_In_opt_ IDXGIAdapter* pAdapter, D3D_DRIVER_TYPE DriverType, HMODULE Software, UINT Flags, _In_reads_opt_( FeatureLevels ) CONST D3D_FEATURE_LEVEL* pFeatureLevels, UINT FeatureLevels, UINT SDKVersion, _COM_Outptr_opt_ ID3D11Device** ppDevice, _Out_opt_ D3D_FEATURE_LEVEL* pFeatureLevel, _COM_Outptr_opt_ ID3D11DeviceContext** ppImmediateContext)
{
	ATLTRACE(atlTraceGeneral, 4, _T("pAdapter 0x%p, DriverType %d, Software 0x%p, Flags 0x%X, pFeatureLevels 0x%p, FeatureLevels %d, SDKVersion 0x%04X, ppDevice 0x%p, pFeatureLevel 0x%p, ppImmediateContext 0x%p\n"), pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, ppDevice, pFeatureLevel, ppImmediateContext);
	ATLASSERT(!pAdapter && DriverType == D3D_DRIVER_TYPE_HARDWARE);
	CComPtr<IDXGIFactory2> pDxgiFactory;
	ATLVERIFY(SUCCEEDED(CreateDXGIFactory2(0, __uuidof(IDXGIFactory2), (VOID**) &pDxgiFactory)));
	CComPtr<IDXGIAdapter> pDxgiAdapter;
	ATLVERIFY(SUCCEEDED(pDxgiFactory->EnumAdapters(1, &pDxgiAdapter)));
	DXGI_ADAPTER_DESC AdapterDescription;
	ATLVERIFY(SUCCEEDED(pDxgiAdapter->GetDesc(&AdapterDescription)));
	ATLTRACE(atlTraceGeneral, 4, _T("AdapterDescription.Description \"%ls\"\n"), AdapterDescription.Description);
	D3D11CREATEDEVICE pD3D11CreateDevice;
	#if defined(EASYHOOK)
		pD3D11CreateDevice = &D3D11CreateDevice;
	#endif // defined(EASYHOOK)
	#if defined(MINHOOK)
		pD3D11CreateDevice = g_pD3D11CreateDevice;
	#endif // defined(MINHOOK)
	ATLASSERT(pD3D11CreateDevice);
	const HRESULT nResult = pD3D11CreateDevice(
		//pAdapter, DriverType, 
		pDxgiAdapter, D3D_DRIVER_TYPE_UNKNOWN,
		Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, ppDevice, pFeatureLevel, ppImmediateContext);
	ATLTRACE(atlTraceGeneral, 4, _T("nResult 0x%08X\n"), nResult);
	return nResult;
}

int main()
{
	#if defined(_DEBUG)
		CTrace::SetLevel(4);
	#endif // defined(_DEBUG)
	ATLVERIFY(SUCCEEDED(CoInitialize(NULL)));
	ATLVERIFY(SUCCEEDED(MFStartup(MF_VERSION)));
	{
		VOID* pD3D11CreateDevice = GetProcAddress(GetModuleHandle(_T("d3d11.dll")), "D3D11CreateDevice");
		#if defined(EASYHOOK)
			// NOTE: EasyHook - Manually adding EasyHook to your C++ project https://easyhook.github.io/tutorials/nativemanuallyaddref.html
			HOOK_TRACE_INFO hHook = { };
			ATLVERIFY(SUCCEEDED(LhInstallHook(pD3D11CreateDevice, &Hook_D3D11CreateDevice, NULL, &hHook)));
			ULONG pAclEntries[] = { 0 };
			ATLVERIFY(SUCCEEDED(LhSetInclusiveACL(pAclEntries, _countof(pAclEntries), &hHook)));
		#endif // defined(EASYHOOK)
		#if defined(MINHOOK)
			// NOTE: https://www.codeproject.com/Articles/44326/MinHook-The-Minimalistic-x-x-API-Hooking-Libra
			ATLVERIFY(MH_Initialize() == MH_OK);
			ATLASSERT(!g_pD3D11CreateDevice);
			ATLVERIFY(MH_CreateHook(pD3D11CreateDevice, &Hook_D3D11CreateDevice, reinterpret_cast<LPVOID*>(&g_pD3D11CreateDevice)) == MH_OK);
			ATLVERIFY(MH_EnableHook(pD3D11CreateDevice) == MH_OK);
		#endif // defined(MINHOOK)

		if(FALSE)
		{
			D3D_FEATURE_LEVEL pFeatureLevels[] = { D3D_FEATURE_LEVEL_10_0 };
			CComPtr<ID3D11Device> pDevice;
			D3D_FEATURE_LEVEL FeatureLevel;
			CComPtr<ID3D11DeviceContext> pDeviceContext;
			const HRESULT nResult = D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_UNKNOWN, NULL, 0, pFeatureLevels, _countof(pFeatureLevels), D3D11_SDK_VERSION, &pDevice, &FeatureLevel, &pDeviceContext);
		}

		class __declspec(uuid("{60F44560-5A20-4857-BFEF-D29773CB8040}")) CFoo; // NVIDIA H.264 Encoder MFT
		CComPtr<IMFTransform> pTransform;
		const HRESULT nCoCreateInstanceResult = pTransform.CoCreateInstance(__uuidof(CFoo));
		_tprintf(_T("nCoCreateInstanceResult 0x%08X\n"), nCoCreateInstanceResult);

		if(FAILED(nCoCreateInstanceResult))
		{
			const HMODULE hModule = LoadLibrary(_T("nvEncMFTH264.dll"));
			_tprintf(_T("hModule 0x%p\n"), hModule);
			typedef HRESULT (STDMETHODCALLTYPE *DLLGETCLASSOBJECT)(__in REFCLSID ClassIdentifier, __in REFIID InterfaceIdentifier, __out VOID** ppvObject);
			const DLLGETCLASSOBJECT pDllGetClassObject = (DLLGETCLASSOBJECT) GetProcAddress(hModule, "DllGetClassObject");
			CComPtr<IClassFactory> pClassFactory;
			const HRESULT nDllGetClassObjectResult = (pDllGetClassObject)(__uuidof(CFoo), __uuidof(IClassFactory), (VOID**) &pClassFactory);
			_tprintf(_T("nDllGetClassObjectResult 0x%08X\n"), nDllGetClassObjectResult);
			ATLASSERT(pClassFactory);
			const HRESULT nCreateInstanceResult = pClassFactory->CreateInstance(NULL, __uuidof(IMFTransform), (VOID**) &pTransform.p);
			_tprintf(_T("nCreateInstanceResult 0x%08X\n"), nCreateInstanceResult);
			pTransform.Release();
			FreeLibrary(hModule);
		}

		if(pTransform)
		{
			CComPtr<IMFAttributes> pAttributes;
			ATLVERIFY(SUCCEEDED(pTransform->GetAttributes(&pAttributes)));
			UINT32 nCount;
			ATLVERIFY(SUCCEEDED(pAttributes->GetCount(&nCount)));
			for(UINT32 nIndex = 0; nIndex < nCount; nIndex++)
			{
				GUID Key;
				PROPVARIANT vValue;
				PropVariantInit(&vValue);
				ATLVERIFY(SUCCEEDED(pAttributes->GetItemByIndex(nIndex, &Key, &vValue)));
				WCHAR pszKey[64] = { 0 };
				ATLVERIFY(StringFromGUID2(Key, pszKey, _countof(pszKey)));
				_tprintf(_T("pszKey %ls, vValue 0x%X %ls\n"), pszKey, vValue.vt, (vValue.vt == VT_LPWSTR) ? vValue.pwszVal : L"");
				ATLVERIFY(SUCCEEDED(PropVariantClear(&vValue)));
			}
		}

		#if defined(EASYHOOK)
			ATLVERIFY(SUCCEEDED(LhUninstallHook(&hHook)));
			ATLVERIFY(SUCCEEDED(LhWaitForPendingRemovals()));
		#endif // defined(EASYHOOK)
		#if defined(MINHOOK)
			ATLASSERT(g_pD3D11CreateDevice);
			ATLVERIFY(MH_DisableHook(pD3D11CreateDevice) == MH_OK);
			g_pD3D11CreateDevice = NULL;
			ATLVERIFY(MH_Uninitialize() == MH_OK);
		#endif // defined(MINHOOK)
	}
	ATLVERIFY(SUCCEEDED(MFShutdown()));
	CoUninitialize();
    return 0;
}

