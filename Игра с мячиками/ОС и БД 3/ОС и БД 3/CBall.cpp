#include "CBall.h"
#include "CHLimiter.h"
CBall::CBall() {}
CBall::~CBall() {}
void CBall::SetParams(double x, double y, double r,
    double v_x, double v_y,
    RECT rect, double m)
{
    this->x = x;
    this->y = y;
    this->r = r;
    this->m = m;
    this->v_x = v_x;
    this->v_y = v_y;
    this->rect = rect;
}
void CBall::Move(DWORD delta_ticks)
{
    double s_delta = ((double)delta_ticks) / 500.0;
    if ((this->x >= rect.right - r) && (this->v_x > 0))
        this->v_x = -(this->v_x);
    if ((this->x <= r) && (this->v_x < 0))
        this->v_x = -(this->v_x);
    if ((this->y >= rect.bottom - r) && (this->v_y > 0))
        this->v_y = -(this->v_y);
    if ((this->y <= r) && (this->v_y < 0))
        this->v_y = -(this->v_y);
    double dx = v_x * s_delta;
    double dy = v_y * s_delta;
    this->x += dx;
    this->y += dy;
}
void CBall::SetBounds(RECT bnds)
{
    this->rect = bnds;
}
void CBall::Draw(HDC dc)
{
    Ellipse(dc, x - r, y - r, x + r, y + r);
}
void CBall::SetColor(int r, int g, int b)
{
}

bool CBall::Idividual()
{
    return true;
}
