#include "Signaling.h"
#include <iostream>
using namespace std;

Signaling::Signaling(Car* car)
{
	this->car = car;
}
Signaling::~Signaling(void)
{
}
float Signaling::cost()
{
	return (15000 + car->cost());
}
void Signaling::getDescription()
{
	car->getDescription();
	cout << " Signaling" << endl;
}
