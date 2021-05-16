#pragma once
#include <windows.h>
#include <windowsx.h>
#include "CHLimiter.h"
class CBall
{
public:    
    double m;
    double x, y;
    double r;
    double v_x, v_y;
    RECT rect;
    CHLimiter* limit1;
    HBRUSH hOld;
    CBall(void);
    virtual ~CBall(void);
    virtual void SetParams(double x, double y, double r,
        double v_x, double v_y,
        RECT rect, double m);
    void Move(DWORD delta_ticks);
    void SetBounds(RECT bnds);
    virtual void Draw(HDC dc);
    virtual void SetColor(int r, int g, int b);
    virtual bool Idividual();
};
