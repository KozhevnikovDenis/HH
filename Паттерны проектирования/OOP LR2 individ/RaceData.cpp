#include "RaceData.h"
#include <iostream>
using namespace std;

RaceData::RaceData(void)
{
	this->observers = new Observers * [3];
	for (int i = 0; i < 3; i++)
	{
		this->observers[i] = 0;
	}
}
RaceData::~RaceData(void)
{
	delete[]observers;
}
void RaceData::registerObserver(Observers* a)
{
	for (int i = 0; i < 3; i++)
	{
		if (observers[i] == 0)
		{
			observers[i] = a;
			return;
		}

	}
	cout << "No positions for Observer " << endl;
}
void RaceData::removeObserver(Observers* a)
{
	for (int i = 0; i < 3; i++)
	{
		if (observers[i] == a)
		{
			observers[i] = 0;
			return;
		}

	}
	cout << "Observer is not in the list " << endl;
}
void RaceData::notifyObserver()
{
	for (int i = 0; i < 3; i++)
	{
		if (observers[i] != 0)
		{
			observers[i]->update(this->position, this->speed, this->time);

		}

	}
}
void RaceData::setMeasurements(float position, float speed, float time)
{
	this->position = position;
	this->speed = speed;
	this->time = time;
	this->notifyObserver();
}
void RaceData::getMeasurements()
{
	float position, speed, time;
	cout << "P= ";
	cin >> position;
	cout << "S= ";
	cin >> speed;
	cout << "T= ";
	cin >> time;
	this->setMeasurements(position, speed, time);
}