#pragma once


// C4InARowField

class C4InARowField : public CWnd
{
	DECLARE_DYNAMIC(C4InARowField)

public:
	C4InARowField();
	virtual ~C4InARowField();

protected:
	DECLARE_MESSAGE_MAP()
private:
	bool RegisterClass();
public:
	afx_msg void OnPaint();
private:
	int fieldLength;
	int fieldWidth;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	void ClearFields();
private:
	void GetFieldPosition(CPoint point, int& xpos, int& ypos);
	int** fields;
	void InitializeFields();
	void DestroyFields();
public:
	afx_msg void OnDestroy();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
private:
	CRect GetRectFromField(int x, int y);
	void DrawX(CPaintDC& dc, CRect rect);
	void DrawO(CPaintDC& dc, CRect rect);
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
private:
	int nSelectedX;
	int nSelectedY;
	void HighlightSelection(CPaintDC& dc);
public:
	afx_msg void OnMouseLeave();
};


