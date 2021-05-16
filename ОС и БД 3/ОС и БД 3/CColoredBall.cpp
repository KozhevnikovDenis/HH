#include "CColoredBall.h"
CColoredBall::CColoredBall(void)
{
	this->hBrush = CreateSolidBrush(RGB(0, 255, 0));
}
CColoredBall::~CColoredBall(void)
{
	DeleteBrush(this->hBrush);
}
void CColoredBall::SetColor(int r1, int g, int b)
{
	DeleteBrush(this->hBrush);
	this->hBrush = CreateSolidBrush(RGB(r1, g, b));
	this->r1 = r1;
	this->g = g;
	this->b = b;
}
void CColoredBall::Draw(HDC dc)
{
	old = SelectBrush(dc, this->hBrush);
	Ellipse(dc, x - r, y - r, x + r, y + r);
	SelectBrush(dc, old);
}
void CColoredBall::DrawBall(HDC dc)
{
	old = SelectBrush(dc, this->hBrush);
	Ellipse(dc, x - r, y - r, x + r, y + r);
	SelectBrush(dc, old);
}

bool CColoredBall::Idividual()
{
	return false;
}
