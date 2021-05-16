#include "Cball.h"

CBall::CBall(double x, double y, double vx, double vy, double r)
{
	dspeed = 20;
	hBrush = CreateSolidBrush(RGB(0, 255, 0));
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
	this->r = r;
	this->prev_ticks = GetTickCount();
}

CBall::~CBall()
{
	DeleteObject(hBrush);
}

void CBall::Draw(HDC dc)
{
	HBRUSH hOldBrush;

	hOldBrush = SelectBrush(dc, hBrush);
	Ellipse(dc, x - r, y - r, x + r, y + r);
	SelectBrush(dc, hOldBrush);
}

void CBall::Move(DWORD ticks)
{
	double s_delta = ((double)(ticks - this->prev_ticks)) / 80.0;

	if ((this->x >= bounds.right - r) && (this->vx > 0))
		this->vx = -(this->vx);
	if ((this->x <= r) && (this->vx < 0))
		this->vx = -(this->vx);
	if ((this->y >= bounds.right - r) && (this->vy > 0))
		this->vy = -(this->vy);
	if ((this->y <= r) && (this->vy < 0))
		this->vy = -(this->vy);

	if (((this->x + r) >= limit1->GetMinX()) && ((this->x - r) <= limit1->GetMaxX()))
	{
		if (this->vy > 0)
		{
			if (((limit1->GetY() - this->y) < this->r) && ((limit1->GetY() - this->y) > 0))
				this->vy = -(this->vy);
		}
		else
		{
			if (((this->y - limit1->GetY()) < this->r) && ((this->y - limit1->GetY()) > 0))
				this->vy = -(this->vy);
		}
	}

	this->prev_ticks = ticks;
	double dx = vx * s_delta;
	double dy = vy * s_delta;
	this->x += dx;
	this->y += dy;
}


void CBall::SetBounds(RECT bnds)
{
	this->bounds = bnds;
}


void CBall::SetHLimiter(CHLimiter* l)
{
	this->limit1 = l;
}


void CBall::SpeedUp()
{
	if ((this->vx < 1 && this->vx > -1) || (this->vy < 1 && this->vy > -1))
	{
		this->vx += 1;
		this->vy += 1;
	}
	double sxy = this->vx;
	this->vx = ((pow((this->vx), 2) + dspeed) / sxy); //прибавляем 20 к квадрату числа
	sxy = this->vy;
	this->vy = ((pow((this->vy), 2) + dspeed) / sxy);
}

void CBall::SpeedDown()
{
	if (this->vx > dspeed || this->vx < -dspeed)
	{
		if ((this->vx < 1 && this->vx > -1) || (this->vy < 1 && this->vy > -1))
		{
			this->vx = 1;
			this->vy = 1;
		}
		double sxy = this->vx;
		this->vx = ((pow((this->vx), 2) - dspeed) / sxy); //вычитаем 20 из квадрата числа
		sxy = this->vy;
		this->vy = ((pow((this->vy), 2) - dspeed) / sxy);
	}
	else
	{
		this->vx = 0; //останавливается
		this->vy = 0;
	}
}
