#include "TicTacHumanPlayer.h"


TicTacHumanPlayer::TicTacHumanPlayer()
{
}

TicTacHumanPlayer::~TicTacHumanPlayer()
{
}


bool TicTacHumanPlayer::MakeMove()
{
	unsigned int col;
	cout << "»грок " << name << ", ваш ход..." << endl;
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
