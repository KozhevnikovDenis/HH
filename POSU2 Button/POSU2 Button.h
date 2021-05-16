#pragma once

// POSU2 Button.h: основной файл заголовка для POSU2 Button.DLL

#if !defined( __AFXCTL_H__ )
#error "включить afxctl.h до включения этого файла"
#endif

#include "resource.h"       // основные символы


// CPOSU2ButtonApp: реализацию см. в файле POSU2 Button.cpp.

class CPOSU2ButtonApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

