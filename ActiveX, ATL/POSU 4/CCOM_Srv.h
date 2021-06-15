#include "Your_interface.h"
#pragma once


// Целевой объект команды CCOM_Srv

class CCOM_Srv : public CCmdTarget
{
	DECLARE_DYNAMIC(CCOM_Srv)

public:
	CCOM_Srv();
	//virtual ~CCOM_Srv();

protected:
	//DECLARE_MESSAGE_MAP()
	virtual ~CCOM_Srv();
	// Generated message map functions
	//{{AFX_MSG(CYur)
	// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CCOM_Srv)
	BEGIN_INTERFACE_PART(Calc, ICalc)
		STDMETHOD_(int, Sum)(int first, int second);
	END_INTERFACE_PART(Calc)
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CYur)
	// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

};


