#include <Windows.h> 
#include <Windowsx.h> 
#include "CBall.h"
#include "CColoredBall.h"
#include "Trap.h"
class CBallsArray
{
	CBall** balls;
	HWND g_mainWnd;
	HWND hWnd;
	int count;
	int max_balls;
	int gF;
public:
	CColoredBall* AddColoredBall();
	CBallsArray(int max_balls);
	virtual ~CBallsArray(void);
	CBall* Add();
	void SetBounds(RECT bnds);
	void Move(DWORD ticks, Trap* trap);
	void Draw(HDC dc);
	void SetGravityFactor(DWORD ticks);
};