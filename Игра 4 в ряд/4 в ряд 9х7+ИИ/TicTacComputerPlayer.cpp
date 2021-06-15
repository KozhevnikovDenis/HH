#include "TicTacComputerPlayer.h"
#include <windows.h>
//#include "TicTacManager.h"



TicTacComputerPlayer::TicTacComputerPlayer()
{
}


TicTacComputerPlayer::~TicTacComputerPlayer()
{
}


bool TicTacComputerPlayer::MakeMove()
{	
	unsigned int col, col0, col1, col2, col3, col4, col5, col6, col7, col8, colFull;
	
	if (FirstOrSecond())
		col = (unsigned int)(rand() % 9);	//если бот на первой позиции (или оба бота)
	if (!FirstOrSecond())
		col = this->board->FindHuman();		//если бот на второй позиции

	srand(GetTickCount());

	if (col == 0)
	{
		col0 = (unsigned int)(rand() % 4);
		cout << "Игрок " << name << ", ходит..." << endl;
		if (this->board->CheckLegal(col0))
		{
			this->board->SetCell(col0, this->cellType);
			return true;
		}
	}

	else if (col == 1)
	{
		int aim = rand() % 5;
		if (aim <= 2)
			col1 = (unsigned int)(rand() % 4);
		if (aim > 2)
			col1 = (unsigned int)(1 + rand() % 4);

		cout << "Игрок " << name << ", ходит..." << endl;
		if (this->board->CheckLegal(col1))
		{
			this->board->SetCell(col1, this->cellType);
			return true;
		}
	}

	else if (col == 2)
	{
		int aim = rand() % 6;
		if (aim <= 1)
			col2 = (unsigned int)(rand() % 4);
		if (1 < aim <= 3)
			col2 = (unsigned int)(1 + rand() % 4);
		if (3 < aim <= 5)
			col2 = (unsigned int)(2 + rand() % 4);

		cout << "Игрок " << name << ", ходит..." << endl;
		if (this->board->CheckLegal(col2))
		{
			this->board->SetCell(col2, this->cellType);
			return true;
		}
	}

	else if (col == 3)
	{
		int aim = rand() % 7;
		if (aim < 1)
			col3 = (unsigned int)(rand() % 4);
		if (1 <= aim <= 3)
			col3 = (unsigned int)(1 + rand() % 4);
		if (3 < aim <= 5)
			col3 = (unsigned int)(2 + rand() % 4);
		if (5 < aim < 7)
			col3 = (unsigned int)(3 + rand() % 4);

		cout << "Игрок " << name << ", ходит..." << endl;
		if (this->board->CheckLegal(col3))
		{
			this->board->SetCell(col3, this->cellType);
			return true;
		}
	}

	else if (col == 4)
	{
		int aim = 1 + rand() % 7;
		if (aim < 2)
			col4 = (unsigned int)(1 + rand() % 4);
		if (2 <= aim <= 4)
			col4 = (unsigned int)(2 + rand() % 4);
		if (4 < aim <= 6)
			col4 = (unsigned int)(3 + rand() % 4);
		if (6 < aim < 8)
			col4 = (unsigned int)(4 + rand() % 4);

		cout << "Игрок " << name << ", ходит..." << endl;
		if (this->board->CheckLegal(col4))
		{
			this->board->SetCell(col4, this->cellType);
			return true;
		}
	}

	else if (col == 5)
	{
		int aim = 2 + rand() % 7;
		if (aim < 3)
			col5 = (unsigned int)(2 + rand() % 4);
		if (3 <= aim < 5)
			col5 = (unsigned int)(3 + rand() % 4);
		if (5 <= aim <= 7)
			col5 = (unsigned int)(4 + rand() % 4);
		if (7 < aim < 9)
			col5 = (unsigned int)(5 + rand() % 4);

		cout << "Игрок " << name << ", ходит..." << endl;
		if (this->board->CheckLegal(col5))
		{
			this->board->SetCell(col5, this->cellType);
			return true;
		}
	}

	else if (col == 6)
	{
		int aim = 3 + rand() % 6;
		if (aim <= 4)
			col6 = (unsigned int)(3 + rand() % 4);
		if (4 < aim <= 6)
			col6 = (unsigned int)(4 + rand() % 4);
		if (6 < aim <= 8)
			col6 = (unsigned int)(5 + rand() % 4);

		cout << "Игрок " << name << ", ходит..." << endl;
		if (this->board->CheckLegal(col6))
		{
			this->board->SetCell(col6, this->cellType);
			return true;
		}
	}

	else if (col == 7)
	{
		int aim = 4 + rand() % 5;
		if (aim <= 6)
			col7 = (unsigned int)(4 + rand() % 4);
		if (aim > 6)
			col7 = (unsigned int)(5 + rand() % 4);

		cout << "Игрок " << name << ", ходит..." << endl;
		if (this->board->CheckLegal(col7))
		{
			this->board->SetCell(col7, this->cellType);
			return true;
		}
	}

	else if (col == 8)
	{
		col8 = (unsigned int)(5 + rand() % 4);
		cout << "Игрок " << name << ", ходит..." << endl;
		if (this->board->CheckLegal(col8))
		{
			this->board->SetCell(col8, this->cellType);
			return true;
		}
	}

	else
	{
		colFull = (unsigned int)(rand() % 9);
		cout << "Игрок " << name << ", ходит..." << endl;
		if (this->board->CheckLegal(colFull))
		{
			this->board->SetCell(colFull, this->cellType);
			return true;
		}
	}



	
	return false;
}


