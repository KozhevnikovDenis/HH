#pragma once
#include "Subject.h"
#include "Observers.h"
class RaceData :
    public Subject
{
    float position, speed, time;
    Observers** observers;
public:
    RaceData(void);
    ~RaceData(void);
    void registerObserver(Observers* a);
    void removeObserver(Observers* a);
    void notifyObserver();
    void setMeasurements(float position, float speed, float time);
    void getMeasurements();

};

