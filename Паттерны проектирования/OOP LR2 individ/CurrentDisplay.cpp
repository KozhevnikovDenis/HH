#include "CurrentDisplay.h"
#include <iostream>
using namespace std;

CurrentDisplay::CurrentDisplay(void)
{
	position = 0;
	speed = 0;
	time = 0;
}
CurrentDisplay::~CurrentDisplay(void)
{
}
void CurrentDisplay::update(float position, float speed, float time)
{
	this->position = position;
	this->speed = speed;
	this->time = time;

}
void CurrentDisplay::display()
{
	cout << "Current position " << position << endl;
	cout << "Current speed " << speed << endl;
	cout << "Current time " << time << endl;
}
