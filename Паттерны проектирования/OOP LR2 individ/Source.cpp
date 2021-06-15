#include "RaceData.h"
#include "CurrentDisplay.h"
#include "StatisticsDisplay.h"#include <iostream>
using namespace std;

void main()
{
	RaceData a;
	StatisticsDisplay b;
	CurrentDisplay c;

	a.registerObserver(&b);
	a.registerObserver(&c);
	int i = 0;
	while (1)
	{
		i++;
		a.getMeasurements();
		if (i % 3 == 0)
			b.display();
		c.display();
	}
}