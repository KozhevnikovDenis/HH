#include "ClimateControl.h"
#include <iostream>
using namespace std;

ClimateControl::ClimateControl(Car* car)
{
	this->car = car;
}
ClimateControl::~ClimateControl(void)
{
}
float ClimateControl::cost()
{
	return (20000 + car->cost());
}
void ClimateControl::getDescription()
{
	car->getDescription();
	cout << " Climate Control" << endl;
}