#include "TicTacPlayer.h"


void TicTacPlayer::SetupPlayer(string name, CellType cellType)
{
	this->name = name;
	this->cellType = cellType;
}


void TicTacPlayer::SetBoard(TicTacBoard* board)
{
	this->board = board;
}


bool TicTacPlayer::MakeMove()
{
	unsigned int col;
	cout << "»грок " << name << ", ваш ход..." << endl;
//	cout << "¬ведите строку: ";
//	cin >> row;
	cout << "¬ведите столбец: ";
	cin >> col;
	cin.clear(); // на случай, если предыдущий ввод завершилс€ с ошибкой
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (this->board->CheckLegal(col))
	{
		this->board->SetCell(col, this->cellType);
		return true;
	}
	return false;
}


string TicTacPlayer::GetName()
{
	return this->name;
}