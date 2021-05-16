#pragma once

// POSU2ButtonPropPage.h: объявление класса страницы свойств CPOSU2ButtonPropPage.


// CPOSU2ButtonPropPage: реализацию см. в POSU2ButtonPropPage.cpp.

class CPOSU2ButtonPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CPOSU2ButtonPropPage)
	DECLARE_OLECREATE_EX(CPOSU2ButtonPropPage)

// Конструктор
public:
	CPOSU2ButtonPropPage();

// Данные диалогового окна
	enum { IDD = IDD_PROPPAGE_POSU2BUTTON };

// Реализация
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	BOOL m_shape;
	afx_msg void OnBnClickedShape();
};

