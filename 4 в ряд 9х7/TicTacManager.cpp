#include "TicTacManager.h"


TicTacManager::~TicTacManager()
{
	delete this->player2;
	delete this->player1;
	delete this->board;
}


bool TicTacManager::Init()
{
	cout << "�������� ���� 9�7..." << endl;
	string playerName;
	/*unsigned l = 9, w = 7;
	cout << "�������� ���� 9�7." << endl;
	this->board = new TicTacBoard(l, w);
	this->player1 = new TicTacPlayer();
	this->player2 = new TicTacPlayer();
	//cin.ignore();*/
	cout << "������� ��� ������ ��������� �: ";
	getline(cin, playerName);
	player1->SetupPlayer(playerName, CellType_X);
	cout << "������� ��� ������ ��������� O: ";
	getline(cin, playerName);
	player2->SetupPlayer(playerName, CellType_O);
	player1->SetBoard(this->board);
	player2->SetBoard(this->board);
	currentPlayer = player1;
	return true;
}


void TicTacManager::ShowBoard()
{
	this->board->Show();
}


void TicTacManager::MakeMove()
{
	ShowBoard();
	while (!currentPlayer->MakeMove())
	{
		ShowBoard();
	}
	if (this->board->CheckEndCondition())
	{
	//	ShowBoard();
		if (this->board->IsVictory())
			cout << "����� " << currentPlayer->GetName() << " �������!" << endl;
		else
			cout << "�����!" << endl;
		this->bGameFinished = true;
		ShowBoard();
		return;
	}
	currentPlayer = (currentPlayer == player1) ? player2 : player1;
}


bool TicTacManager::IsGameFinished()
{
	return bGameFinished;
}