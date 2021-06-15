#pragma once

// POSU2ButtonCtrl.h: объявление класса элемента управления ActiveX CPOSU2ButtonCtrl.


// CPOSU2ButtonCtrl: реализацию см. в POSU2ButtonCtrl.cpp.

class CPOSU2ButtonCtrl : public COleControl
{
	DECLARE_DYNCREATE(CPOSU2ButtonCtrl)

// Конструктор
public:
	CPOSU2ButtonCtrl();

// Переопределение
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// Реализация
protected:
	~CPOSU2ButtonCtrl();

	DECLARE_OLECREATE_EX(CPOSU2ButtonCtrl)    // Фабрика класса и guid
	DECLARE_OLETYPELIB(CPOSU2ButtonCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CPOSU2ButtonCtrl)     // ИД страницы свойств
	DECLARE_OLECTLTYPE(CPOSU2ButtonCtrl)		// Введите имя и промежуточное состояние

// Схемы сообщений
	DECLARE_MESSAGE_MAP()

// Схемы подготовки к отправке
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Схемы событий
	DECLARE_EVENT_MAP()

// Подготовка к отправке и ИД событий
public:
	enum {
		dispidselect = 4,
		dispidshape = 3
	};
protected:
	VARIANT_BOOL Getshape();
	void Setshape(VARIANT_BOOL newVal);
	VARIANT_BOOL Getselect();
	void Setselect(VARIANT_BOOL newVal);
public:
	VARIANT_BOOL m_shape;
	VARIANT_BOOL m_select = 1;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

