#pragma once

#include <windows.h>
#include <windowsx.h>
#include "HLimiter.h"
#include <cmath>

class CBall
{
	HBRUSH hBrush;
	DWORD prev_ticks;
	double x, y;
	double vx, vy;
	double r;
	//double dspeed = 20;
	double dspeed;
	RECT bounds;
	CHLimiter* limit1;
public:
	CBall(double x, double y, double vx, double vy, double r);
	~CBall();
	void Draw(HDC dc);
	void Move(DWORD ticks);
	void SetBounds(RECT bnds);
	void SetHLimiter(CHLimiter* l);
	void SpeedUp();
	void SpeedDown();
};