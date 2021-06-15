#pragma once
#include "AccessoriesDecorator.h"
class ParkingSensors :
    public AccessoriesDecorator
{
    Car* car;
public:
    ParkingSensors(Car* car);
    ~ParkingSensors();
    float cost();
    void getDescription();
};

