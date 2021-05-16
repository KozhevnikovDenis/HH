#pragma once
#include <iostream>
using namespace std;
#include "SeatLocation.h"
#include "TicketRefund.h"
class Ticket
{
	SeatLocation* l1;
	TicketRefund* r1;
public:
	void SetSeatLocation(SeatLocation* l)
	{
		this->l1 = l;
	}

	void SetTicketRefund(TicketRefund* r)
	{
		this->r1 = r;
	}

	void Buy()
	{
		l1->Buy();
	}

	void Refund()
	{
		r1->Refund();
	}

	virtual void display() = 0;
};

