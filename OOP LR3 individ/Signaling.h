#pragma once
#include "AccessoriesDecorator.h"
class Signaling :
    public AccessoriesDecorator
{
    Car* car;
public:
    Signaling(Car* car);
    ~Signaling();
    float cost();
    void getDescription();
};

