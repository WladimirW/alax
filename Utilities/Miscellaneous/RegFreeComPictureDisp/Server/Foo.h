// Foo.h : Declaration of the CFoo

#pragma once

#include <atlstr.h>
#include "resource.h"       // main symbols
#include "Server_i.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
	#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;

// CFoo

class ATL_NO_VTABLE CFoo :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFoo, &CLSID_Foo>,
	public IDispatchImpl<IFoo, &IID_IFoo, &LIBID_ServerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CFoo()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CFoo)
	COM_INTERFACE_ENTRY(IFoo)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:


	STDMETHOD(Init)(BSTR User, BSTR Password) override
	{
		ATLTRACE(_T("User \"%s\", Password \"%s\"\n"), CString(User), CString(Password));
		return S_OK;
	}
	STDMETHOD(SetBitmap)(BSTR szObjectType, IPictureDisp* szBitmap) override
	{
		ATLTRACE(_T("szObjectType \"%s\", szBitmap 0x%p\n"), CString(szObjectType), szBitmap);
		return S_OK;
	}

};

OBJECT_ENTRY_AUTO(__uuidof(Foo), CFoo)
