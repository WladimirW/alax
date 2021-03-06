// NOTE: https://stackoverflow.com/questions/48172751/dxgi-monitors-enumeration-does-not-give-full-size-for-dell-p2715q-monitor

#include <winsdkver.h>
#include <sdkddkver.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <ShellScalingAPI.h>
#include <dxgi.h>

#pragma comment(lib, "shcore.lib")
#pragma comment(lib, "dxgi.lib")

using namespace std;

int main()
{
	//SetProcessDpiAwareness(PROCESS_SYSTEM_DPI_AWARE);

	IDXGIFactory1* pFactory1;

	HRESULT hr = CreateDXGIFactory1(__uuidof(IDXGIFactory1), (void**)(&pFactory1));

	if (FAILED(hr))
	{
		wcout << L"CreateDXGIFactory1 failed. " << endl;
		return 0;
	}

	for (UINT i = 0;; i++)
	{
		IDXGIAdapter1* pAdapter1 = nullptr;

		hr = pFactory1->EnumAdapters1(i, &pAdapter1);

		if (hr == DXGI_ERROR_NOT_FOUND)
		{
			// no more adapters
			break;
		}

		if (FAILED(hr))
		{
			wcout << L"EnumAdapters1 failed. " << endl;
			return 0;
		}

		DXGI_ADAPTER_DESC1 desc;

		hr = pAdapter1->GetDesc1(&desc);

		if (FAILED(hr))
		{
			wcout << L"GetDesc1 failed. " << endl;
			return 0;
		}

		wcout << L"Adapter: " << desc.Description << endl;

		for (UINT j = 0;; j++)
		{
			IDXGIOutput *pOutput = nullptr;

			HRESULT hr = pAdapter1->EnumOutputs(j, &pOutput);

			if (hr == DXGI_ERROR_NOT_FOUND)
			{
				// no more outputs
				break;
			}

			if (FAILED(hr))
			{
				wcout << L"EnumOutputs failed. " << endl;
				return 0;
			}

			DXGI_OUTPUT_DESC desc;

			hr = pOutput->GetDesc(&desc);

			if (FAILED(hr))
			{
				wcout << L"GetDesc1 failed. " << endl;
				return 0;
			}

			wcout << L"  Output: " << desc.DeviceName <<
				L"  (" << desc.DesktopCoordinates.left << L"," << desc.DesktopCoordinates.top << L")-(" <<
				(desc.DesktopCoordinates.right - desc.DesktopCoordinates.left) << L"," <<
				(desc.DesktopCoordinates.bottom - desc.DesktopCoordinates.top) << L")" << endl;

		}
	}

	return 0;
}