#include "Trap.h"

Trap::Trap(double x, double y, double F, double r)
{
	this->x = x;
	this->y = y;
	this->F = F;
	this->r = r;
}

Trap::~Trap(void)
{
}

void Trap::Draw(HDC dc)
{
	pBrush = CreateSolidBrush(RGB(190, 0, 100));
	SelectBrush(dc, pBrush);
	Ellipse(dc, x - 25, y + 25, x + 25, y - 25);
}

void Trap::MoveBall(CBall* b)
{
	double x_dist = this->x - b->x;
	double y_dist = this->y - b->y;
	double x2_dist = x_dist * x_dist;
	double y2_dist = y_dist * y_dist;
	double dist2 = x2_dist + y2_dist;
	double dist = sqrt(dist2);
	if (dist > r)
		return;

	if (dist2 < 0.6)
		dist2 = 0.6;

	double x_factor = (F * (x_dist / dist)) / (dist2);
	double y_factor = (F * (y_dist / dist)) / (dist2);
	b->v_x += x_factor;
	b->v_y += y_factor;
}