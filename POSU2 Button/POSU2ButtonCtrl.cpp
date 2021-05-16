// POSU2ButtonCtrl.cpp: реализация класса элемента управления ActiveX CPOSU2ButtonCtrl.

#include "pch.h"
#include "framework.h"
#include "POSU2 Button.h"
#include "POSU2ButtonCtrl.h"
#include "POSU2ButtonPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CPOSU2ButtonCtrl, COleControl)

// Схема сообщений

BEGIN_MESSAGE_MAP(CPOSU2ButtonCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// Схема подготовки к отправке

BEGIN_DISPATCH_MAP(CPOSU2ButtonCtrl, COleControl)
	DISP_FUNCTION_ID(CPOSU2ButtonCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_PROPERTY_EX_ID(CPOSU2ButtonCtrl, "shape", dispidshape, Getshape, Setshape, VT_BOOL)
	DISP_PROPERTY_EX_ID(CPOSU2ButtonCtrl, "select", dispidselect, Getselect, Setselect, VT_BOOL)
END_DISPATCH_MAP()

// Схема событий

BEGIN_EVENT_MAP(CPOSU2ButtonCtrl, COleControl)
END_EVENT_MAP()

// Страницы свойств

// TODO: при необходимости добавьте дополнительные страницы свойств.  Не забудьте увеличить значение счетчика.
/*BEGIN_PROPPAGEIDS(CPOSU2ButtonCtrl, 1)
	PROPPAGEID(CPOSU2ButtonPropPage::guid)
END_PROPPAGEIDS(CPOSU2ButtonCtrl)*/
BEGIN_PROPPAGEIDS(CPOSU2ButtonCtrl, 2)
	PROPPAGEID(CPOSU2ButtonPropPage::guid)
	PROPPAGEID(CLSID_CColorPropPage)
END_PROPPAGEIDS(CPOSU2ButtonCtrl)

// Инициализировать фабрику класса и guid

IMPLEMENT_OLECREATE_EX(CPOSU2ButtonCtrl, "MFCACTIVEXCONTRO.POSU2ButtonCtrl.1",
	0xd7187b45,0xb33b,0x4408,0xae,0xfa,0xaf,0x36,0xd2,0x84,0x55,0x29)

// Введите ИД и версию библиотеки

IMPLEMENT_OLETYPELIB(CPOSU2ButtonCtrl, _tlid, _wVerMajor, _wVerMinor)

// ИД интерфейса

const IID IID_DPOSU2Button = {0x334d5076,0xf138,0x4947,{0x81,0x25,0xf3,0x51,0xaf,0x76,0x13,0x91}};
const IID IID_DPOSU2ButtonEvents = {0x7afe8d83,0x95ae,0x44f1,{0x9a,0xb4,0x87,0x8e,0x81,0x5f,0x09,0x54}};

// Сведения о типах элементов управления

static const DWORD _dwPOSU2ButtonOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CPOSU2ButtonCtrl, IDS_POSU2BUTTON, _dwPOSU2ButtonOleMisc)

// CPOSU2ButtonCtrl::CPOSU2ButtonCtrlFactory::UpdateRegistry -
// Добавляет или удаляет записи системного реестра для CPOSU2ButtonCtrl

BOOL CPOSU2ButtonCtrl::CPOSU2ButtonCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: убедитесь, что элементы управления следуют правилам модели изолированных потоков.
	// Дополнительные сведения см. в MFC TechNote 64.
	// Если элемент управления не соответствует правилам модели изоляции, то
	// необходимо модифицировать приведенный ниже код, изменив значение 6-го параметра с
	// afxRegApartmentThreading на 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_POSU2BUTTON,
			IDB_POSU2BUTTON,
			afxRegApartmentThreading,
			_dwPOSU2ButtonOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CPOSU2ButtonCtrl::CPOSU2ButtonCtrl — конструктор

CPOSU2ButtonCtrl::CPOSU2ButtonCtrl()
{
	InitializeIIDs(&IID_DPOSU2Button, &IID_DPOSU2ButtonEvents);
	// TODO: Инициализируйте здесь данные экземпляра элемента управления.
}

// CPOSU2ButtonCtrl::~CPOSU2ButtonCtrl — деструктор

CPOSU2ButtonCtrl::~CPOSU2ButtonCtrl()
{
	// TODO: Выполните здесь очистку данных экземпляра элемента управления.
}

// CPOSU2ButtonCtrl::OnDraw — функция рисования

void CPOSU2ButtonCtrl::OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
/*{
	if (!pdc)
		return;

	// TODO: Замените следующий код собственным кодом рисования.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}*/
{
	CPen pen;// объект типа «карандаш»
	CBrush fBrush, bBrush; //объекты типа «кисть» pdc ->SaveDC();
	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0)); //цвет карандаша черный
	bBrush.CreateSolidBrush(TranslateColor(AmbientBackColor())); //задание цвета заднего фона
	fBrush.CreateSolidBrush(Getselect() ? RGB(0, 0, 0) : RGB(0, 255, 0)); //задание переднего фона
	pdc->FillRect(rcBounds, &bBrush);//задание заднего фона в виде закрашенного прямоугольникацветом заднего фона
		pdc->SelectObject(&pen);
	pdc->SelectObject(&fBrush); // выбор другой «кисти»
	if (m_shape) // задание формы объекты
		pdc->Ellipse(&rcBounds);//рисование эллипса
	else
		pdc->Rectangle(&rcBounds);//рисование прямоугольника
	pdc->RestoreDC(-1);
}

// CPOSU2ButtonCtrl::DoPropExchange — поддержка сохраняемости

void CPOSU2ButtonCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Вызывать функции PX_ для каждого постоянного настраиваемого свойства.
}


// CPOSU2ButtonCtrl::OnResetState — сброс элемента управления к состоянию по умолчанию

void CPOSU2ButtonCtrl::OnResetState()
{
	COleControl::OnResetState();  // Сбрасывает значения по умолчанию, найденные в DoPropExchange

	// TODO: Сбросьте здесь состояние любого другого элемента управления.
}


// CPOSU2ButtonCtrl::AboutBox — отображение окна "О программе" для пользователя

void CPOSU2ButtonCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_POSU2BUTTON);
	dlgAbout.DoModal();
}


// Обработчики сообщений CPOSU2ButtonCtrl


VARIANT_BOOL CPOSU2ButtonCtrl::Getshape()
/*{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Добавьте сюда код обработчика отправки

	return VARIANT_TRUE;
}*/
{
	return m_shape;
}


void CPOSU2ButtonCtrl::Setshape(VARIANT_BOOL newVal)
/*{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Добавьте сюда код обработчика свойств

	SetModifiedFlag();
}*/
{
	m_shape = newVal;
	InvalidateControl();
}


VARIANT_BOOL CPOSU2ButtonCtrl::Getselect()
/*{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Добавьте сюда код обработчика отправки

	return VARIANT_TRUE;
}*/
{
	return m_select;
}


void CPOSU2ButtonCtrl::Setselect(VARIANT_BOOL newVal)
/*{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Добавьте сюда код обработчика свойств

	SetModifiedFlag();
}*/
{
	m_select = newVal;
	InvalidateControl();
}


void CPOSU2ButtonCtrl::OnLButtonDown(UINT nFlags, CPoint point)
/*{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	COleControl::OnLButtonDown(nFlags, point);
}*/
{
	m_select = !m_select;
	InvalidateControl();
}


void CPOSU2ButtonCtrl::OnRButtonDown(UINT nFlags, CPoint point)
/*{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	COleControl::OnRButtonDown(nFlags, point);
}*/
{
	m_shape = !m_shape;
	InvalidateControl();
}