#include "Rectangle.h"
#include <stdio.h>

Rectangle::Rectangle(void)
{
	printf("Rectangle Constructor called\n");
}


Rectangle::~Rectangle(void)
{
	printf("Rectangle Destructor called\n");
}

double Rectangle::GetSquare()
{
	printf("baldej= %.0f\n",a*b);
	return 0;
	//printf("bldejok= \n");
	//return a*b;
}

void Rectangle::PrintName()
{
	printf("eto Rectangle\n");
}