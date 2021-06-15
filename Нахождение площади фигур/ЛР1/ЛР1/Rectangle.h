#pragma once
#include "figure.h"
class Rectangle :
	public Figure
{
public:
	Rectangle(void);
	~Rectangle(void);
	double GetSquare();
	double a,b;
	void PrintName();
};

