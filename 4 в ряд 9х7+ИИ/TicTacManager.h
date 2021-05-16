#pragma once
#include "TicTacPlayer.h"
#include "TicTacHumanPlayer.h"
#include "TicTacComputerPlayer.h"

class TicTacManager
{
protected:
	TicTacBoard* board = new TicTacBoard(9, 7);
	TicTacPlayer* player1;
	TicTacPlayer* player2;
	TicTacPlayer* currentPlayer;
	bool bGameFinished = false;
public:
	TicTacManager();
	virtual ~TicTacManager();
	bool Init();
	void ShowBoard();
	void MakeMove();
	bool IsGameFinished();
	int seed = 0;
	int Seed();
};

