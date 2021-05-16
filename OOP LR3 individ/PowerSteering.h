#pragma once
#include "AccessoriesDecorator.h"
class PowerSteering :
    public AccessoriesDecorator
{
    Car* car;
public:
    PowerSteering(Car* car);
    ~PowerSteering();
    float cost();
    void getDescription();
};

