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

int main()
{
	ATLVERIFY(SUCCEEDED(CoInitialize(NULL)));
	{
		ATLVERIFY(SUCCEEDED(MFStartup(MF_VERSION)));
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
	}
	CoUninitialize();
    return 0;
}

