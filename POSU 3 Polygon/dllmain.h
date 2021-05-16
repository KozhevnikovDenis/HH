// dllmain.h: объявление класса модуля.

class CPOSU3PolygonModule : public ATL::CAtlDllModuleT< CPOSU3PolygonModule >
{
public :
	DECLARE_LIBID(LIBID_POSU3PolygonLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_POSU3POLYGON, "{f31f28d0-75c1-4da8-8b68-cc3030ac2059}")
};

extern class CPOSU3PolygonModule _AtlModule;
