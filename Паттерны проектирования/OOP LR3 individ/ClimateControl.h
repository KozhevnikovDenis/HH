#pragma once
#include "AccessoriesDecorator.h"
class ClimateControl :
    public AccessoriesDecorator
{
    Car* car;
public:
    ClimateControl(Car* car);
    ~ClimateControl();
    float cost();
    void getDescription();

};

