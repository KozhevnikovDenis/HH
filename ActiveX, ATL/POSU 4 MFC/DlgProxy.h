
// DlgProxy.h: файл заголовка
//

#pragma once

class CPOSU4MFCDlg;


// Целевой объект команды CPOSU4MFCDlgAutoProxy

class CPOSU4MFCDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CPOSU4MFCDlgAutoProxy)

	CPOSU4MFCDlgAutoProxy();           // защищенный конструктор, используемый при динамическом создании

// Атрибуты
public:
	CPOSU4MFCDlg* m_pDialog;

// Операции
public:

// Переопределение
	public:
	virtual void OnFinalRelease();

// Реализация
protected:
	virtual ~CPOSU4MFCDlgAutoProxy();

	// Созданные функции схемы сообщений

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CPOSU4MFCDlgAutoProxy)

	// Автоматически созданные функции диспетчерской карты OLE

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

