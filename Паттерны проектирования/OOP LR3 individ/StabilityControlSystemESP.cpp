#include "StabilityControlSystemESP.h"
#include <iostream>
using namespace std;

StabilityControlSystemESP::StabilityControlSystemESP(Car* car)
{
	this->car = car;
}
StabilityControlSystemESP::~StabilityControlSystemESP(void)
{
}
float StabilityControlSystemESP::cost()
{
	return (125000 + car->cost());
}
void StabilityControlSystemESP::getDescription()
{
	car->getDescription();
	cout << " Stability Control System ESP" << endl;
}
