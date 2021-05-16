#include "StatisticsDisplay.h"
#include <iostream>
using namespace std;

StatisticsDisplay::StatisticsDisplay(void)
{
	for (int i = 0; i < 3; i++)
	{
		array_position[i] = 0;
		array_speed[i] = 0;
		array_time[i] = 0;
	}
}
StatisticsDisplay::~StatisticsDisplay(void)
{
}
void StatisticsDisplay::display()
{
	cout << "Average position: " << average_position << endl;
	cout << "Average speed: " << average_speed << endl;
	cout << "Average time: " << average_time << endl;
}
void StatisticsDisplay::update(float position, float speed, float time)
{

	for (int j = 1;j >= 0;j--)
	{
		array_position[j + 1] = array_position[j];
		array_speed[j + 1] = array_speed[j];
		array_time[j + 1] = array_time[j];
	}
	array_position[0] = position;
	array_speed[0] = speed;
	array_time[0] = time;
	float sum_position = 0;
	float sum_speed = 0;
	float sum_time = 0;
	for (int i = 0;i < 3;i++)
	{
		sum_position += array_position[i];
		sum_speed += array_speed[i];
		sum_time += array_time[i];
	}
	average_position = sum_position / 3;
	average_speed = sum_speed / 3;
	average_time = sum_time / 3;
}