#include "ParkingSensors.h"
#include <iostream>
using namespace std;

ParkingSensors::ParkingSensors(Car* car)
{
	this->car = car;
}
ParkingSensors::~ParkingSensors(void)
{
}
float ParkingSensors::cost()
{
	return (5000 + car->cost());
}
void ParkingSensors::getDescription()
{
	car->getDescription();
	cout << " Parking Sensors" << endl;
}
