#include "TicTacManager.h"


TicTacManager::TicTacManager()
{
}


TicTacManager::~TicTacManager()
{
	delete this->player2;
	delete this->player1;
	delete this->board;
}


bool TicTacManager::Init()
{
	cout << "���� 4 � ��� 9�7." << endl;
	cout << "�������� ���� 9�7..." << endl;
	string playerName;
	int playertype;
	
	cout << "������� ��� ������ #1 (1 - �������, ����� ������ ����� - ���������) : ";
	cin >> playertype;
	cin.clear(); // �� ������, ���� ���������� ���� ���������� � �������
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (playertype == 1)
		this->player1 = new TicTacHumanPlayer();
	else 
	{

		this->player1 = new TicTacComputerPlayer();
		player1->bFirstOrSecond = true;
		cout << "������� ������� ��������� �� (����� �� 1 - 10): ";
		cin >> seed;
		cin.clear(); // �� ������, ���� ���������� ���� ���������� � �������
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//PlayerType();
		//srand(playertype);
	}
//	cin.clear(); // �� ������, ���� ���������� ���� ���������� � �������
//	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "������� ��� ������ #2 (1 - �������, ����� ������ ����� - ���������) : ";
	cin >> playertype;
	cin.clear(); // �� ������, ���� ���������� ���� ���������� � �������
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (playertype == 1)
		this->player2 = new TicTacHumanPlayer();
	else
	{
		this->player2 = new TicTacComputerPlayer();
		player2->bFirstOrSecond = false;
		cout << "������� ������� ��������� �� (����� �� 1 - 10): ";
		cin >> seed;
		cin.clear(); // �� ������, ���� ���������� ���� ���������� � �������
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//srand(playertype);
	}
//	cin.clear(); // �� ������, ���� ���������� ���� ���������� � �������
//	cin.ignore(numeric_limits<streamsize>::max(), '\n');

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


int TicTacManager::Seed()
{
	return seed;
}