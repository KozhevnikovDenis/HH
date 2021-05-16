// C4InARowField.cpp: файл реализации
//

#include "pch.h"
#include "4 in a row 9x7.h"
#include "C4InARowField.h"


#define FOURINAROWFIELD_CLASSNAME L"4InARowField"
#define FIELDNUMBERSSPACE 30

// C4InARowField

IMPLEMENT_DYNAMIC(C4InARowField, CWnd)

C4InARowField::C4InARowField()
{

	fieldLength = 9;
	fieldWidth = 7;
	fields = nullptr;
	InitializeFields();
	this->RegisterClass();
	nSelectedX = -1;
	nSelectedY = -1;
}

C4InARowField::~C4InARowField()
{
}


BEGIN_MESSAGE_MAP(C4InARowField, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_DESTROY()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()



// Обработчики сообщений C4InARowField




bool C4InARowField::RegisterClass()
{
	WNDCLASS wndcls;
	HINSTANCE hInst = AfxGetInstanceHandle();

	if (!(::GetClassInfo(hInst, FOURINAROWFIELD_CLASSNAME, &wndcls)))
	{
		wndcls.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
		wndcls.lpfnWndProc = ::DefWindowProc;
		wndcls.cbClsExtra = 0;
		wndcls.cbWndExtra = 0;
		wndcls.hInstance = hInst;
		wndcls.hIcon = NULL;
		wndcls.hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		wndcls.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
		wndcls.lpszMenuName = NULL;
		wndcls.lpszClassName = FOURINAROWFIELD_CLASSNAME;
		if (!AfxRegisterClass(&wndcls))
		{
			AfxThrowResourceException();
			return FALSE;
		}
	}

	return TRUE;
}


void C4InARowField::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: добавьте свой код обработчика сообщений
					   // Не вызывать CWnd::OnPaint() для сообщений рисования

	CRect rect;
	GetClientRect(&rect);

	CPen ourPen;
	HGDIOBJ oldPen;
	ourPen.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));

	oldPen = dc.SelectObject(ourPen);

	int hPartSize = (rect.right - FIELDNUMBERSSPACE) / fieldLength;
	int vPartSize = (rect.bottom - FIELDNUMBERSSPACE) / fieldWidth;

	this->HighlightSelection(dc);

	for (int i = 0; i < fieldLength + 1; i++)
	{
		dc.MoveTo(FIELDNUMBERSSPACE + i * hPartSize, FIELDNUMBERSSPACE);
		dc.LineTo(FIELDNUMBERSSPACE + i * hPartSize, rect.bottom);
		dc.MoveTo(FIELDNUMBERSSPACE, FIELDNUMBERSSPACE + i * vPartSize);
		dc.LineTo(rect.right, FIELDNUMBERSSPACE + i * vPartSize);
	}

	dc.SetTextColor(RGB(225, 0, 0));
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextAlign(TA_TOP | TA_LEFT);

	for (int i = 0; i < fieldLength; i++)
	{
		CString str;
		str.Format(L"%d", i);
		dc.TextOutW(0, FIELDNUMBERSSPACE / 2 + vPartSize / 2 + i * vPartSize, str);
		dc.TextOutW(FIELDNUMBERSSPACE / 2 + hPartSize / 2 + i * hPartSize, 0, str);
	}

	if (fields != nullptr)
	{
		for (int i = 0; i < fieldWidth; i++)
		{
			for (int j = 0; j < fieldLength; j++)
			{
				if (fields[i][j] == 1)
					this->DrawX(dc, this->GetRectFromField(j, i));
				if (fields[i][j] == 2)
					this->DrawO(dc, this->GetRectFromField(j, i));
			}
		}
	}

/*	dc.MoveTo(0, 0);
	dc.LineTo(rect.right, 0);
	dc.LineTo(rect.right, rect.bottom);
	dc.LineTo(0, rect.bottom);
	dc.LineTo(0 , 0);

	dc.SetTextColor(RGB(225, 0, 0));
	dc.SetTextAlign(TA_TOP | TA_LEFT);
	dc.SetBkMode(TRANSPARENT);
	dc.TextOutW(0, 0, L"я устал прогать");*/

	dc.SelectObject(oldPen);
	ourPen.DeleteObject();
}


void C4InARowField::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	int x, y;
	this->GetFieldPosition(point, x, y);

	if (fields != nullptr)
	{
		for (int i = fieldWidth - 1; i >= 0; i--)
		{
			if ((fields[i][x] != 1) && (fields[i][x] != 2))
			{
				fields[i][x] = 1;
				this->Invalidate();
				break;
			}

			if ((fields[i][x] == 1) || (fields[i][x] == 2))
				continue;
		}
	}

/*	CString str;
	str.Format(L"X=%d Y=%d", x, y);
	AfxMessageBox(str);*/

	CWnd::OnLButtonDown(nFlags, point);
}


void C4InARowField::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	int x, y;
	this->GetFieldPosition(point, x, y);

	if (fields != nullptr)
	{
		for (int i = fieldWidth - 1; i >= 0; i--)
		{
			if ((fields[i][x] != 1) && (fields[i][x] != 2))
			{
				fields[i][x] = 2;
				this->Invalidate();
				break;
			}

			if ((fields[i][x] == 1) || (fields[i][x] == 2))
				continue;
		}
	}

	CWnd::OnRButtonDown(nFlags, point);
}


void C4InARowField::GetFieldPosition(CPoint point, int& xpos, int& ypos)
{
	// TODO: Добавьте сюда код реализации.
	CRect rect;
	GetClientRect(&rect);
	int hPartSize = (rect.right - FIELDNUMBERSSPACE) / fieldLength;
	int vPartSize = (rect.bottom - FIELDNUMBERSSPACE) / fieldWidth;
	for (int i = 0; i < fieldLength; i++)
	{
		if ((point.x > FIELDNUMBERSSPACE + i * hPartSize) && (point.x < FIELDNUMBERSSPACE + (i + 1) * hPartSize))
			xpos = i;
	}
	for (int i = 0; i < fieldWidth; i++)
	{
		if ((point.y > FIELDNUMBERSSPACE + i * vPartSize) && (point.y < FIELDNUMBERSSPACE + (i + 1) * vPartSize))
			ypos = i;
	}
}


void C4InARowField::InitializeFields()
{
	// TODO: Добавьте сюда код реализации.
	if (fields == nullptr)
	{
		fields = new int* [fieldWidth];
		for (int i = 0; i < fieldWidth; i++)
			fields[i] = new int[fieldLength];
	}

	ClearFields();
}


void C4InARowField::DestroyFields()
{
	// TODO: Добавьте сюда код реализации.
	if (fields != nullptr)
	{
		for (int i = 0; i < fieldWidth; i++)
			delete[] fields[i];
		delete[] fields;
		fields = nullptr;
	}
}


void C4InARowField::ClearFields()
{
	// TODO: Добавьте сюда код реализации.
	if (fields != nullptr)
	{
		for (int i = 0; i < fieldWidth; i++)
			for (int j = 0; j < fieldLength; j++)
				fields[i][j] = 0;

	}
}


void C4InARowField::OnDestroy()
{
	CWnd::OnDestroy();
	DestroyFields();
	// TODO: добавьте свой код обработчика сообщений
}




CRect C4InARowField::GetRectFromField(int x, int y)
{
	// TODO: Добавьте сюда код реализации.
	CRect rect;
	CRect rectWnd;
	GetClientRect(&rectWnd);
	int hPartSize = (rectWnd.right - FIELDNUMBERSSPACE) / fieldLength;
	int vPartSize = (rectWnd.bottom - FIELDNUMBERSSPACE) / fieldWidth;

	rect.left = FIELDNUMBERSSPACE + x * hPartSize + 1;
	rect.top = FIELDNUMBERSSPACE + y * vPartSize + 1;
	rect.right = FIELDNUMBERSSPACE + ((x + 1) * hPartSize) - 1;
	rect.bottom = FIELDNUMBERSSPACE + ((y + 1) * vPartSize) - 1;

	return rect;
}


void C4InARowField::DrawX(CPaintDC& dc, CRect rect)
{
	// TODO: Добавьте сюда код реализации.
	CPen pen;
	pen.CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
	HGDIOBJ oldPen = dc.SelectObject(pen);

	dc.MoveTo(rect.left + 4, rect.top + 4);
	dc.LineTo(rect.right - 4, rect.bottom - 4);
	dc.MoveTo(rect.left + 4, rect.bottom - 4);
	dc.LineTo(rect.right - 4, rect.top + 4);

	dc.SelectObject(oldPen);
	pen.DeleteObject();
}


void C4InARowField::DrawO(CPaintDC& dc, CRect rect)
{
	// TODO: Добавьте сюда код реализации.
	CPen pen;
	pen.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	HGDIOBJ oldPen = dc.SelectObject(pen);
	HGDIOBJ oldBrush = dc.SelectObject(GetStockObject(HOLLOW_BRUSH));

	dc.Ellipse(rect.left + 4, rect.top + 4, rect.right - 4, rect.bottom - 4);

	dc.SelectObject(oldPen);
	dc.SelectObject(oldBrush);
	pen.DeleteObject();
}


void C4InARowField::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	int x, y;
	GetFieldPosition(point, x, y);
	if ((nSelectedX != x) || (nSelectedY != y))
	{
		nSelectedX = x;
		nSelectedY = y;
		this->Invalidate();
	}

	TRACKMOUSEEVENT tme;
	tme.cbSize = sizeof(tme);
	tme.hwndTrack = this->m_hWnd;
	tme.dwFlags = TME_LEAVE;
	tme.dwHoverTime = HOVER_DEFAULT;

	TrackMouseEvent(&tme);

	CWnd::OnMouseMove(nFlags, point);
}


void C4InARowField::HighlightSelection(CPaintDC& dc)
{
	// TODO: Добавьте сюда код реализации.
	if ((nSelectedX < 0) || (nSelectedY < 0))
		return;

	CRect rect = GetRectFromField(nSelectedX, nSelectedY);
	CBrush brush;
	brush.CreateSolidBrush(RGB(125, 249, 255));
	HGDIOBJ oldBrush = dc.SelectObject(brush);
	dc.Rectangle(rect);
	dc.SelectObject(oldBrush);
	brush.DeleteObject();
}


void C4InARowField::OnMouseLeave()
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	nSelectedX = -1;
	nSelectedY = -1;
	this->Invalidate();

	CWnd::OnMouseLeave();
}
