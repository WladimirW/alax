// Foo.h : Declaration of the CFoo

#pragma once
#include "resource.h"       // main symbols



#include "Host_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CFoo

class ATL_NO_VTABLE CFoo :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFoo, &CLSID_Foo>,
	public IDispatchImpl<IFoo, &IID_IFoo, &LIBID_HostLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CFoo()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FOO)


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

// IFoo
	STDMETHOD(Bar)()
	{
		MessageBox(GetActiveWindow(), _T("Hello, 32-bit World!"), _T("Information"), MB_OK);
		return S_OK;
	}

};

OBJECT_ENTRY_AUTO(__uuidof(Foo), CFoo)
