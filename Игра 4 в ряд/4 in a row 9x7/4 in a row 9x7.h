
// 4 in a row 9x7.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMy4inarow9x7App:
// Сведения о реализации этого класса: 4 in a row 9x7.cpp
//

class CMy4inarow9x7App : public CWinApp
{
public:
	CMy4inarow9x7App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMy4inarow9x7App theApp;
