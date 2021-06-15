#include "Romb.h"
#include <iostream>
using namespace std;


Romb::Romb(void)
{
}


Romb::~Romb(void)
{
}

double Romb::GetSquare()
{
	cout << "Enter side="; cin >> a;
	cout << "Enter height="; cin >> b;
	cout << "Square of romb=" << a*b << endl;
	return a*b;
}

void Romb::PrintName()
{
	cout << "Beautiful romb" << endl;
}