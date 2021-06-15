// POSU 4.h: основной файл заголовка для библиотеки DLL POSU 4
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CPOSU4App
// Реализацию этого класса см. в файле POSU 4.cpp
//

class CPOSU4App : public CWinApp
{
public:
	CPOSU4App();

// Переопределение
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
