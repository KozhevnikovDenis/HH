#include "Car.h"
#include "AccessoriesDecorator.h"
#include "KIA.h"
#include "Nissan.h"
#include "Toyota.h"
#include "ClimateControl.h"
#include "ParkingSensors.h"
#include "PowerSteering.h"
#include "Signaling.h"
#include "StabilityControlSystemESP.h"
#include <iostream>
using namespace std;
void main(void)
{
	Car* car1 = new KIA();
	car1 = new ClimateControl(car1);
	car1 = new PowerSteering(car1);
	car1 = new StabilityControlSystemESP(car1);
	car1->getDescription();
	cout << " rub " << car1->cost() << endl << endl;

	Car* car2 = new Nissan();
	car2 = new ParkingSensors(car2);
	car2 = new Signaling(car2);
	car2 = new PowerSteering(car2);
	car2->getDescription();
	cout << " rub " << car2->cost() << endl << endl;

	Car* car3 = new Toyota();
	car3 = new StabilityControlSystemESP(car3);
	car3 = new Signaling(car3);
	car3 = new ClimateControl(car3);
	car3->getDescription();
	cout << " rub " << car3->cost() << endl << endl;


}