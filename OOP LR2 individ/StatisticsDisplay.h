#pragma once
#include "Observers.h"
#include "DisplayElement.h"
class StatisticsDisplay :
    public Observers, public DisplayElement
{
    float average_position, average_speed, average_time;
    float array_position[3];
    float array_speed[3];
    float array_time[3];
    public:
        StatisticsDisplay(void);
        ~StatisticsDisplay(void);
        void update(float position, float speed, float time);
        void display();
};

