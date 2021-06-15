#pragma once
#include "Observers.h"

class Subject
{
	virtual void registerObserver(Observers*) = 0;
	virtual void removeObserver(Observers*) = 0;
	virtual void notifyObserver() = 0;

};
