#pragma once
#include "Car.h"
class AccessoriesDecorator :
	public Car
{
public:
	virtual void getDescription() = 0;
};