#include "Rectangle.h"
#include <iostream>
using namespace std;


Rectangle::Rectangle(void)
{
//	cout << "Rectangle Constructor called!" << endl;
}


Rectangle::~Rectangle(void)
{
//	cout << "Rectangle Destructor called!" << endl;
}

double Rectangle::GetSquare()
{
	cout << "Enter length="; cin >> a;
	cout << "Enter height="; cin >> b;
	cout << "Square of rectangle=" << a*b << endl;
	return a*b;
}

void Rectangle::PrintName()
{
	cout << "Beautiful rectangle" << endl;
}