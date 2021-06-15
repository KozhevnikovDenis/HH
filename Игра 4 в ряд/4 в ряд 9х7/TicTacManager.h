#pragma once
#include "TicTacBoard.h"
#include "TicTacPlayer.h"
class TicTacManager
{
private:
	TicTacBoard* board = new TicTacBoard(9, 7);
	TicTacPlayer* player1 = new TicTacPlayer();
	TicTacPlayer* player2 = new TicTacPlayer();
	TicTacPlayer* currentPlayer;
	bool bGameFinished = false;
public:
//	TicTacManager();
	virtual ~TicTacManager();
	bool Init();
	void ShowBoard();
	void MakeMove();
	bool IsGameFinished();
};

