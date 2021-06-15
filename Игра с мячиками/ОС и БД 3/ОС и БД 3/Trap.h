#pragma once
#include "CBall.h"
#include <cmath>
class Trap
{

public:
	HBRUSH pBrush;
	double x, y;
	double F;
	double r;

	Trap(double x, double y, double F, double r);
	virtual ~Trap(void);
	virtual void Draw(HDC dc);
	virtual void MoveBall(CBall* b);
};