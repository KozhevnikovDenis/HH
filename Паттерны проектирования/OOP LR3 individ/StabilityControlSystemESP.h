#pragma once
#include "AccessoriesDecorator.h"
class StabilityControlSystemESP :
    public AccessoriesDecorator
{
    Car* car;
public:
    StabilityControlSystemESP(Car* car);
    ~StabilityControlSystemESP();
    float cost();
    void getDescription();
};

