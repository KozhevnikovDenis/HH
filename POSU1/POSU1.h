
// POSU1.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CPOSU1App:
// Сведения о реализации этого класса: POSU1.cpp
//

class CPOSU1App : public CWinApp
{
public:
	CPOSU1App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CPOSU1App theApp;
