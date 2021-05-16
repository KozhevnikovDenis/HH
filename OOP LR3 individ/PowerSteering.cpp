#include "PowerSteering.h"
#include <iostream>
using namespace std;

PowerSteering::PowerSteering(Car* car)
{
	this->car = car;
}
PowerSteering::~PowerSteering(void)
{
}
float PowerSteering::cost()
{
	return (40000 + car->cost());
}
void PowerSteering::getDescription()
{
	car->getDescription();
	cout << " Power Steering" << endl;
}
