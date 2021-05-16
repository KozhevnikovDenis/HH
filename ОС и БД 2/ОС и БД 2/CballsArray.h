#include <Windows.h> 
#include <Windowsx.h> 
#include "CBall.h"
#include "ColloredBall.h"
class CBallsArray
{
	CBall** balls; 
	HWND g_mainWnd; 
	HWND hWnd; 
	int count; 
	int max_balls;
public:
	CColoredBall* AddColoredBall();
	CBallsArray(int max_balls); 
	virtual ~CBallsArray(void); 
	CBall* Add(); 
	void SetBounds(RECT bnds); 
	void Move(DWORD ticks); 
	void Draw(HDC dc);
};