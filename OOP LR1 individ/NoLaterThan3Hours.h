#pragma once
#include "TicketRefund.h"
class NoLaterThan3Hours :
    public TicketRefund
{
public:
    NoLaterThan3Hours();
    ~NoLaterThan3Hours();
    void Refund();
};

