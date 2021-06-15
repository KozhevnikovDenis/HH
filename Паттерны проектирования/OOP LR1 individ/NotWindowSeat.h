#pragma once
#include "SeatLocation.h"
class NotWindowSeat :
    public SeatLocation
{
public:
    NotWindowSeat();
    ~NotWindowSeat();
    void Buy();
};

