#pragma once
#include "CBall.h"
class CColoredBall :
	public CBall
{
	HBRUSH hBrush;
	HBRUSH old;
	int r1, g, b;
public:
	CColoredBall(void);
	virtual ~CColoredBall(void);
	virtual void SetColor(int r, int g, int b);
	void Draw(HDC dc);
	void DrawBall(HDC dc);
	bool Idividual();
};
