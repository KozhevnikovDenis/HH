
// DlgProxy.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "POSU 4 MFC.h"
#include "DlgProxy.h"
#include "POSU 4 MFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPOSU4MFCDlgAutoProxy

IMPLEMENT_DYNCREATE(CPOSU4MFCDlgAutoProxy, CCmdTarget)

CPOSU4MFCDlgAutoProxy::CPOSU4MFCDlgAutoProxy()
{
	EnableAutomation();

	// Чтобы приложение работало, пока объект
	//	автоматизации активен, конструктор вызывает AfxOleLockApp.
	AfxOleLockApp();

	// Получает доступ к диалоговому окну через указатель
	//  главного окна приложения.  Задает внутренний указатель прокси-сервера для
	//  доступа к диалогу, а также задает обратный указатель диалога на этот
	//  прокси-сервер.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CPOSU4MFCDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CPOSU4MFCDlg)))
		{
			m_pDialog = reinterpret_cast<CPOSU4MFCDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CPOSU4MFCDlgAutoProxy::~CPOSU4MFCDlgAutoProxy()
{
	// Чтобы прервать работу приложения, когда все объекты создаются
	// 	автоматически, деструктор вызывает AfxOleUnlockApp.
	//  Среди прочего будет уничтожено главное диалоговое окно
	if (m_pDialog != nullptr)
		m_pDialog->m_pAutoProxy = nullptr;
	AfxOleUnlockApp();
}

void CPOSU4MFCDlgAutoProxy::OnFinalRelease()
{
	// Когда будет освобождена последняя ссылка на объект автоматизации,
	// Будет вызван OnFinalRelease.  Базовый класс автоматически
	// удалит объект.  Перед вызовом базового класса требуется
	// дополнительная очистка объекта.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CPOSU4MFCDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CPOSU4MFCDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// Примечание. Мы добавили поддержку для IID_IPOSU4MFC, чтобы обеспечить безопасную с точки зрения типов привязку
//  из VBA.  Этот IID должен соответствовать GUID, связанному с
//  disp-интерфейс в файле .IDL.

// {ed5d5f12-d574-4c84-92df-8e7f3d3c407a}
static const IID IID_IPOSU4MFC =
{0xed5d5f12,0xd574,0x4c84,{0x92,0xdf,0x8e,0x7f,0x3d,0x3c,0x40,0x7a}};

BEGIN_INTERFACE_MAP(CPOSU4MFCDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CPOSU4MFCDlgAutoProxy, IID_IPOSU4MFC, Dispatch)
END_INTERFACE_MAP()

// Макрос IMPLEMENT_OLECREATE2 определен в pch.h этого проекта
// {7b26a58b-20d9-47c8-8f15-11eff99a2183}
IMPLEMENT_OLECREATE2(CPOSU4MFCDlgAutoProxy, "POSU4MFC.Application", 0x7b26a58b,0x20d9,0x47c8,0x8f,0x15,0x11,0xef,0xf9,0x9a,0x21,0x83)


// Обработчики сообщений CPOSU4MFCDlgAutoProxy
