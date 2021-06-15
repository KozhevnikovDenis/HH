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
	cout << "����� " << name << ", ��� ���..." << endl;
//	cout << "������� ������: ";
//	cin >> row;
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


string TicTacPlayer::GetName()
{
	return this->name;
}