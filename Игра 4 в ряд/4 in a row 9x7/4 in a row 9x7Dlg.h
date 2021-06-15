
// 4 in a row 9x7Dlg.h: файл заголовка
//

#pragma once
#include "C4InARowField.h"


// Диалоговое окно CMy4inarow9x7Dlg
class CMy4inarow9x7Dlg : public CDialogEx
{
// Создание
public:
	CMy4inarow9x7Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY4INAROW9X7_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;
	C4InARowField tttField;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
