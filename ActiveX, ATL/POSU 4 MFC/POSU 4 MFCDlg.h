
// POSU 4 MFCDlg.h: файл заголовка
//

#pragma once

class CPOSU4MFCDlgAutoProxy;


// Диалоговое окно CPOSU4MFCDlg
class CPOSU4MFCDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPOSU4MFCDlg);
	friend class CPOSU4MFCDlgAutoProxy;

// Создание
public:
	CPOSU4MFCDlg(CWnd* pParent = nullptr);	// стандартный конструктор
	virtual ~CPOSU4MFCDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POSU4MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	CPOSU4MFCDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
};
