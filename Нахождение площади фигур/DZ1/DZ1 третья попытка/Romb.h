#pragma once
#include "figure.h"
class Romb :
	public Figure
{
public:
	Romb(void);
	~Romb(void);
	double GetSquare();
	void PrintName();
	double a,b;
};