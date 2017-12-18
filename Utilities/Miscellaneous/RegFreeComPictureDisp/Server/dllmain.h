// dllmain.h : Declaration of module class.

class CServerModule : public ATL::CAtlDllModuleT< CServerModule >
{
public :
	DECLARE_LIBID(LIBID_ServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_SERVER, "{2ebd7a11-bdfd-4c27-9922-9e702f13c84c}")
};

extern class CServerModule _AtlModule;
