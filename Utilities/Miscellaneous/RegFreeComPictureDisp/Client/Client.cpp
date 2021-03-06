// Client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <afxdisp.h>
#include <atlbase.h>
#include <atlcom.h>

#import "libid:2ebd7a11-bdfd-4c27-9922-9e702f13c84c" no_namespace raw_interfaces_only

class CFooDriver :
	public COleDispatchDriver
{
public:
	BOOL Init(LPCTSTR User, LPCTSTR Password)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_BSTR VTS_BSTR;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			 User, Password);
		return result;
	}
	BOOL SetBitmap(LPCTSTR szObjectType, LPPICTUREDISP szBitmap)
	{
		BOOL result;
		static BYTE parms[] =
			VTS_BSTR VTS_DISPATCH;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms,
			szObjectType, szBitmap);
		return result;
	}
};

int main()
{
	ATLVERIFY(SUCCEEDED(CoInitializeEx(NULL, COINIT_APARTMENTTHREADED)));
	{
		CFooDriver p;
		ATLVERIFY(p.CreateDispatch(__uuidof(Foo)));
		p.Init(_T("User"), _T("Password"));
		CComPtr<IDispatch> pPictureDispatch;
		ATLVERIFY(SUCCEEDED(OleLoadPictureFile(CComVariant(_T("D:\\DSCF1116.JPG")), &pPictureDispatch)));
		const CComQIPtr<IPictureDisp> pPictureDisp = pPictureDispatch;
		ATLASSERT(pPictureDisp);
		p.SetBitmap(_T("ObjectType"), pPictureDisp);
	}
	CoUninitialize();
    return 0;
}

/*

D:\...\RegFreeComPictureDisp\Debug>ManifestComDependency-Win32.exe Client.exe /i /r Server.dll /a Server.dll /e Client.exe.manifest.xml
Opening file: Client.exe
Manifest found: 381 bytes
Updating assembly identity "Client.exe"
Looking for "Server.dll" file elements to remove
Looking for file "Server.dll" to add as file element
Adding element
Exporting manifest to file:
Saving resource in file: Client.exe
Save complete

D:\...\RegFreeComPictureDisp\Debug>regsvr32 /u Server.dll

D:\...\RegFreeComPictureDisp\Debug>client

*/