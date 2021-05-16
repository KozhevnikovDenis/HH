#pragma once
#include "TicketRefund.h"
class NoRefund :
    public TicketRefund
{
public:
    NoRefund();
    ~NoRefund();
    void Refund();
};

