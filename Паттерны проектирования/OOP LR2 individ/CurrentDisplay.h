#pragma once
#include "Observers.h"
#include "DisplayElement.h"
class CurrentDisplay :
    public Observers, public DisplayElement
{
    float position, speed, time;

public:
    CurrentDisplay(void);
    ~CurrentDisplay(void);
    void update(float position, float speed, float time);
    void display();
};

