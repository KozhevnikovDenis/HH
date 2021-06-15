#include "CBallsArray.h" 
#include "CColoredBall.h"
CBallsArray::CBallsArray(int max_balls)
{
	this->count = 0;
	this->max_balls = max_balls;
	this->balls = new CBall * [max_balls];
}
CBallsArray::~CBallsArray()
{
	for (int i = 0; i < count; i++)
		delete this->balls[i];
	delete[] this->balls;
}
CBall* CBallsArray::Add()
{
	if (count >= max_balls)
		return NULL;
	count++; balls[count - 1] = new CBall();
	return balls[count - 1];
}
void CBallsArray::Move(DWORD ticks, Trap* trap)
{
	CBall* ball1;
	CBall* ball2;
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			ball1 = this->balls[i];
			ball2 = this->balls[j];
			double C_x = ball2->x - ball1->x;
			double C_y = ball2->y - ball1->y;
			double C2 = C_x * C_x + C_y * C_y; //квадрат расстояния между центрами шаров
			if (C2 <= ((ball1->r + ball2->r) * (ball1->r + ball2->r))) //проверка, что квадрат расстояние междну шарами меньше квадрата их радиусов
			{

				double AC_scalar = ball1->v_x * C_x + ball1->v_y * C_y;
				double BC_scalar = ball2->v_x * C_x + ball2->v_y * C_y;

				double Ap_v_x = (C_x * AC_scalar) / C2;
				double Ap_v_y = (C_y * AC_scalar) / C2;

				double At_v_x = ball1->v_x - Ap_v_x;
				double At_v_y = ball1->v_y - Ap_v_y;

				double Bp_v_x = (C_x * BC_scalar) / C2;
				double Bp_v_y = (C_y * BC_scalar) / C2;

				double Bt_v_x = ball2->v_x - Bp_v_x;
				double Bt_v_y = ball2->v_y - Bp_v_y;

				ball1->v_x = (Bp_v_x * ball2->m + At_v_x * ball1->m) / ball1->m;
				ball1->v_y = (Bp_v_y * ball1->m + At_v_y * ball2->m) / ball1->m;
				ball2->v_x = (Ap_v_x * ball2->m + Bt_v_x * ball1->m) / ball2->m;
				ball2->v_y = (Ap_v_y * ball1->m + Bt_v_y * ball2->m) / ball2->m;
			}
		}
	}
	for (int i = 0; i < count; i++)
	{
		if (balls[i]->Idividual())
			trap->MoveBall(balls[i]);
		balls[i]->Move(ticks);
	}
}
void CBallsArray::Draw(HDC dc)
{
	for (int i = 0; i < count; i++)
		balls[i]->Draw(dc);
}
void CBallsArray::SetGravityFactor(DWORD ticks)
{
	gF=15;
	for (int i = 0; i < count; i++)		
			balls[i]->v_y += this->gF;
	for (int i = 0; i < count; i++)
		balls[i]->Move(ticks);
}
void CBallsArray::SetBounds(RECT bnds)
{
	for (int i = 0; i < count; i++)
		balls[i]->SetBounds(bnds);
}
CColoredBall* CBallsArray::AddColoredBall()
{
	if (count >= max_balls)
		return NULL;
	count++;
	balls[count - 1] = new CColoredBall();
	return (CColoredBall*)(balls[count - 1]);
}