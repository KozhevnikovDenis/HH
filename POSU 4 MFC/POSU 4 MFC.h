
// POSU 4 MFC.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CPOSU4MFCApp:
// Сведения о реализации этого класса: POSU 4 MFC.cpp
//

class CPOSU4MFCApp : public CWinApp
{
public:
	CPOSU4MFCApp();

// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CPOSU4MFCApp theApp;
