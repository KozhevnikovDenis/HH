#include "EconomyClass.h"
#include "BusinessAndFirstClass.h"
#include "LastMinuteTickets.h"
#include "WindowSeat.h"
#include "NotWindowSeat.h"
#include "NoLaterThan3Hours.h"
#include "NoLaterThan3Days.h"
#include "NoRefund.h"
#include <iostream>
using namespace std;
int main()
{
	Ticket** t;
	int a, n;
	SeatLocation* sl_WindowSeat, * sl_NotWindowSeat;
	TicketRefund* tr_NoLaterThan3Hours, * tr_NoLaterThan3Days, * tr_NoRefund;

	sl_WindowSeat = new WindowSeat();
	sl_NotWindowSeat = new NotWindowSeat();
	tr_NoLaterThan3Hours = new NoLaterThan3Hours();
	tr_NoLaterThan3Days = new NoLaterThan3Days();
	tr_NoRefund = new NoRefund();

	cout << "How many tickets do you need?" << endl;
	cin >> a;
	t = new Ticket* [a];

	for (int i = 0; i < a; i++)
	{
		cout << endl << "Ticket #" << i + 1 << endl;
		cout << "Enter ticket-type: 1 - Economy class, 2 - Business and first class, 3 - Last minute tickets" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			t[i] = new EconomyClass();
			cout << "Enter seat-type: 1 - Next to the window, 2 - Not next to the window" << endl;
			cin >> n;			switch (n)			{			case 1:				t[i]->SetSeatLocation(sl_WindowSeat);				break;			case 2:				t[i]->SetSeatLocation(sl_NotWindowSeat);				break;			default:				t[i]->SetSeatLocation(sl_NotWindowSeat);				cout << "\terror1. sl_NotWindowSeat" << endl;				break;			}
			t[i]->SetTicketRefund(tr_NoLaterThan3Days);
			cout << "The refund fee is 50$." << endl;
			break;
		case 2:
			t[i] = new BusinessAndFirstClass();
			cout << "Enter seat-type: 1 - Next to the window, 2 - Not next to the window" << endl;
			cin >> n;			switch (n)			{			case 1:				t[i]->SetSeatLocation(sl_WindowSeat);				break;			case 2:				t[i]->SetSeatLocation(sl_NotWindowSeat);				break;			default:				t[i]->SetSeatLocation(sl_NotWindowSeat);				cout << "\terror2. sl_NotWindowSeat" << endl;				break;			}			cout << "Enter post-tickett-type: 1 - Business, 2 - First" << endl;
			cin >> n;			switch (n)			{			case 1:				t[i]->SetTicketRefund(tr_NoLaterThan3Days);				cout << "The refund fee is 50$" << endl;				break;			case 2:				t[i]->SetTicketRefund(tr_NoLaterThan3Hours);				cout << "No refund fee." << endl;				break;			default:				t[i]->SetTicketRefund(tr_NoLaterThan3Days);				cout << "\terror3. tr_NoLaterThan3Days" << endl;				break;			}			break;
		case 3:
			t[i] = new LastMinuteTickets();
			cout << "Enter seat-type: 1 - Next to the window, 2 - Not next to the window" << endl;
			cin >> n;			switch (n)			{			case 1:				t[i]->SetSeatLocation(sl_WindowSeat);				break;			case 2:				t[i]->SetSeatLocation(sl_NotWindowSeat);				break;			default:				t[i]->SetSeatLocation(sl_NotWindowSeat);				cout << "\terror4. sl_NotWindowSeat" << endl;				break;			}			t[i]->SetTicketRefund(tr_NoRefund);			cout << "Ticket refund is not possible." << endl;			break;		default:
			t[i] = new EconomyClass();
			t[i]->SetSeatLocation(sl_NotWindowSeat);
			t[i]->SetTicketRefund(tr_NoLaterThan3Days);
			cout << "\terror5. default" << endl;
			break;		}

	}

	cout << endl << "Result: " << endl;
	for (int i = 0; i < a; i++)
	{
		t[i]->Buy();
		t[i]->Refund();
		t[i]->display();
	}


	for (int i = 0; i < a; i++)
	{
		delete t[i];
	}
	delete[] t;
	delete sl_WindowSeat;
	delete sl_NotWindowSeat;
	delete tr_NoLaterThan3Hours;
	delete tr_NoLaterThan3Days;
	delete tr_NoRefund;

	return 0;
}