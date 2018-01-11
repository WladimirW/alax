// NOTE: https://stackoverflow.com/questions/48207677/dxgi-1-5-duplicateoutput1-fails-with-dxgi-error-unsupported-0x887a0004

#include <winsdkver.h>
#include <sdkddkver.h>
#include <stdio.h>
#include <tchar.h>
#include <d3d11.h>
#include <dxgi1_5.h>
#include <atlbase.h>
#include <atlcom.h>

#pragma comment(lib, "d3d11.lib")

int main()
{
    ID3D11Device *device;
    D3D_FEATURE_LEVEL levels[] = { D3D_FEATURE_LEVEL_11_1 };
    D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, 0, levels, ARRAYSIZE(levels), D3D11_SDK_VERSION, &device, NULL, NULL);

    IDXGIDevice *dxDevice;
    device->QueryInterface<IDXGIDevice>(&dxDevice);

    IDXGIAdapter *adapter;
    dxDevice->GetAdapter(&adapter);

	//DXGI_ADAPTER_DESC AdapterDescription;
	//ATLENSURE_SUCCEEDED(adapter->GetDesc(&AdapterDescription));

    IDXGIOutput *output;
    adapter->EnumOutputs(0, &output);

    IDXGIOutput5 *output5;
    output->QueryInterface<IDXGIOutput5>(&output5);

	//CComPtr<IDXGIFactory> pFactory;
	//adapter->GetParent(__uuidof(IDXGIFactory), (VOID**) &pFactory);
	//CComQIPtr<IDXGIFactory1> pFactory1 = pFactory;

    const DXGI_FORMAT formats[] = { DXGI_FORMAT_B8G8R8A8_UNORM };
    CComPtr<IDXGIOutputDuplication> outputDuplication;
    const HRESULT nDuplicateOutput1Result = output5->DuplicateOutput1(device, 0, ARRAYSIZE(formats), formats, &outputDuplication); // 0x887A0004?
	_tprintf(_T("nDuplicateOutput1Result 0x%08X\n"), nDuplicateOutput1Result);
	if(FAILED(nDuplicateOutput1Result))
	{
		const HRESULT nDuplicateOutputResult = output5->DuplicateOutput(device, &outputDuplication);
		_tprintf(_T("nDuplicateOutputResult 0x%08X\n"), nDuplicateOutput1Result);
	}
	if(outputDuplication)
	{
		DXGI_OUTDUPL_DESC OutputDeplicationDescription;
		outputDuplication->GetDesc(&OutputDeplicationDescription);
	}

    return 0;
}

