#pragma once
#include "TicketRefund.h"
class NoLaterThan3Days :
    public TicketRefund
{
public:
    NoLaterThan3Days();
    ~NoLaterThan3Days();
    void Refund();
};

