// POSU2 Button.cpp: реализация CPOSU2ButtonApp и регистрация библиотеки DLL.

#include "pch.h"
#include "framework.h"
#include "POSU2 Button.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CPOSU2ButtonApp theApp;

const GUID CDECL _tlid = {0x1941665f,0x54b8,0x4657,{0x97,0xe5,0x16,0x74,0xb0,0x4b,0x07,0x57}};
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CPOSU2ButtonApp::InitInstance — инициализация библиотеки DLL

BOOL CPOSU2ButtonApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Добавьте здесь свой код инициализации модуля.
	}

	return bInit;
}



// CPOSU2ButtonApp::ExitInstance — завершение библиотеки DLL

int CPOSU2ButtonApp::ExitInstance()
{
	// TODO: Добавьте здесь свой код завершения работы модуля.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - добавляет записи в системный реестр

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - удаляет записи из системного реестра

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
