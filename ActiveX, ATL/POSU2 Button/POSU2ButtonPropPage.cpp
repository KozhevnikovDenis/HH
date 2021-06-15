// POSU2ButtonPropPage.cpp: реализация класса страницы свойств CPOSU2ButtonPropPage.

#include "pch.h"
#include "framework.h"
#include "POSU2 Button.h"
#include "POSU2ButtonPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CPOSU2ButtonPropPage, COlePropertyPage)

// Схема сообщений

BEGIN_MESSAGE_MAP(CPOSU2ButtonPropPage, COlePropertyPage)
	ON_BN_CLICKED(IDC_Shape, &CPOSU2ButtonPropPage::OnBnClickedShape)
END_MESSAGE_MAP()

// Инициализировать фабрика класса и guid

IMPLEMENT_OLECREATE_EX(CPOSU2ButtonPropPage, "MFCACTIVEXCONT.POSU2ButtonPropPage.1",
	0x6235046b,0xe5a6,0x4c63,0xa3,0x1b,0x29,0x2e,0x0a,0xdd,0x0b,0x3d)

// CPOSU2ButtonPropPage::CPOSU2ButtonPropPageFactory::UpdateRegistry -
// Добавляет или удаляет записи системного реестра для CPOSU2ButtonPropPage

BOOL CPOSU2ButtonPropPage::CPOSU2ButtonPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_POSU2BUTTON_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, nullptr);
}

// CPOSU2ButtonPropPage::CPOSU2ButtonPropPage — конструктор

CPOSU2ButtonPropPage::CPOSU2ButtonPropPage() :
	COlePropertyPage(IDD, IDS_POSU2BUTTON_PPG_CAPTION)
	, m_shape(FALSE)
{
}

// CPOSU2ButtonPropPage::DoDataExchange — перемещение данных между страницей и свойствами

void CPOSU2ButtonPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
	DDX_Check(pDX, IDC_Shape, m_shape);
	DDP_Check(pDX, IDC_Shape, m_shape, _T("shape"));
}

// Обработчики сообщений CPOSU2ButtonPropPage


void CPOSU2ButtonPropPage::OnBnClickedShape()
{
	// TODO: добавьте свой код обработчика уведомлений
}
