#pragma once
#include "figure.h"
class Rectangle :
	public Figure
{

public:
	Rectangle(void);
	~Rectangle(void);
	double GetSquare();
	void PrintName();
	double a,b;
};

