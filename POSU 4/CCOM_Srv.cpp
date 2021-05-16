// CCOM_Srv.cpp: файл реализации
//

#include "pch.h"
#include "POSU 4.h"
#include "CCOM_Srv.h"


// CCOM_Srv

IMPLEMENT_DYNAMIC(CCOM_Srv, CCmdTarget)

// {283D6643-E294-49DF-86EA-F1787F2773CF}
IMPLEMENT_OLECREATE(CCOM_Srv, "YOUR",
	0x283d6643, 0xe294, 0x49df, 0x86, 0xea, 0xf1, 0x78, 0x7f, 0x27, 0x73, 0xcf);

CCOM_Srv::CCOM_Srv()
{
}

CCOM_Srv::~CCOM_Srv()
{
}


BEGIN_MESSAGE_MAP(CCOM_Srv, CCmdTarget)
END_MESSAGE_MAP()
BEGIN_INTERFACE_MAP(CCOM_Srv, CCmdTarget)
	INTERFACE_PART(CCOM_Srv, CCOM_Srv::guid, Dispatch)
	INTERFACE_PART(CCOM_Srv, IID_ICalc, Calc)
END_INTERFACE_MAP()
BEGIN_DISPATCH_MAP(CCOM_Srv, CCmdTarget)
END_DISPATCH_MAP()


// Обработчики сообщений CCOM_Srv
// CYur message handlers
STDMETHODIMP_(ULONG) CCOM_Srv::XCalc::AddRef()
{
	TRACE("CYur::XCalc::AddRef\n");
	METHOD_PROLOGUE(CCOM_Srv, Calc)
		return pThis->ExternalAddRef();
}
STDMETHODIMP_(ULONG) CCOM_Srv::XCalc::Release()
{
	TRACE("CYur::XCalc::Release\n");
	METHOD_PROLOGUE(CCOM_Srv, Calc)
		return pThis->ExternalRelease();
}
STDMETHODIMP CCOM_Srv::XCalc::QueryInterface(REFIID iid, LPVOID* ppvObj)
{
	TRACE("CYur::XCalc::QueryInterface\n");
	METHOD_PROLOGUE(CCOM_Srv, Calc)
		return pThis->ExternalQueryInterface(&iid, ppvObj);
}
STDMETHODIMP_(int) CCOM_Srv::XCalc::Sum(int first, int second)
{
	return (first + second);
}
