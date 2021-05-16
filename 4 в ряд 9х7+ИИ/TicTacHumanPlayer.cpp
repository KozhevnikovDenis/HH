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
	cout << "����� " << name << ", ��� ���..." << endl;
	cout << "������� �������: ";
	cin >> col;
	cin.clear(); // �� ������, ���� ���������� ���� ���������� � �������
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (this->board->CheckLegal(col))
	{
		this->board->SetCell(col, this->cellType);
		return true;
	}
	return false;
}
