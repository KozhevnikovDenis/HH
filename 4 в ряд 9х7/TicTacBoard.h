#pragma once
#include "CellType.h"
#include "pch.h"
class TicTacBoard
{
private:
//	int length = 9;
//	int width = 7;
	unsigned int length;
	unsigned int width;
	CellType** cells;
	bool bVictory = false;
	bool IsRowMade();
	bool IsColumnMade();
	bool IsDiagMade();
	bool IsBoardFull();
public:
	TicTacBoard(unsigned int length_board, unsigned int width_board);
	virtual ~TicTacBoard();
	void Show();
	void SetCell(unsigned int xpos, CellType ct);
	bool CheckLegal(unsigned int xpos);
	bool CheckEndCondition();
	bool IsVictory();
};

