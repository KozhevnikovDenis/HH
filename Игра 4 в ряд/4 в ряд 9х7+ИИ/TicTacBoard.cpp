#include "TicTacBoard.h"


/*TicTacBoard::TicTacBoard(TicTacBoard* board)
{
	this->length = length;
	this->width = width;
	cells = new CellType * [width];
	for (unsigned int i = 0; i < width; i++)
		cells[i] = new CellType[length];

	for (unsigned int i = 0; i < width; i++)
		for (unsigned int j = 0; j < length; j++)
			cells[i][j] = board->cells[i][j];
}*/


TicTacBoard::TicTacBoard(unsigned int length_board, unsigned int width_board)
{
	this->length = length_board;
	this->width = width_board;

	cells = new CellType * [width_board];
	for (unsigned int i = 0; i < width_board; i++)
		cells[i] = new CellType[length_board];

	for (unsigned int i = 0; i < width_board; i++)
		for (unsigned int j = 0; j < length_board; j++)
			cells[i][j] = CellType_Empty;
}


TicTacBoard::~TicTacBoard()
{
	for (unsigned int i = 0; i < width; i++)
		delete[] cells[i];
	delete[] cells;
}


void TicTacBoard::Show()
{
	cout << "  ";
	for (unsigned int j = 0; j < length; j++)
		cout << j << " ";
	cout << endl;

	for (unsigned int i = 0; i < width; i++)
	{
		cout << i << " ";
		for (unsigned int j = 0; j < length; j++)
		{
			switch (cells[i][j])
			{
			case CellType_X:
				cout << "X";
				break;
			case CellType_O:
				cout << "O";
				break;
			case CellType_Empty:
				cout << "-";
				break;
			}
			cout << " ";
		}
		cout << endl;
	}
}


void TicTacBoard::SetCell(unsigned int xpos, CellType ct)
{
	for (int i = (int)width - 1; i >= 0; i--)
	{
		if (cells[i][xpos] == CellType_Empty)
		{
			cells[i][xpos] = ct;
			break;
		}
		if (cells[i][xpos] != CellType_Empty)
			continue;
	}
}


unsigned int TicTacBoard::FindHuman()
{
	for (int j = 2; j < length - 2; j++)
	{
		if (cells[width - 1][j] == CellType_X)
			return j;
	}
	for (int j = 0; j < length - 7; j++)
	{
		if (cells[width - 1][j] == CellType_X)
			return j;
	}
	for (int j = 7; j < length; j++)
	{
		if (cells[width - 1][j] == CellType_X)
			return j;
	}
	return 0;
}



bool TicTacBoard::CheckLegal(unsigned int xpos)
{
	if ((xpos < 0) || (xpos > length - 1))
	{
		cout << "Выбран недопустимый столбец!" << endl;
		return false;
	}
	for (int i = (int)width - 1; i >= 0; i--)
	{
		if (cells[i][xpos] == CellType_Empty)
			return true;
	}
	cout << "Столбец заполнен!" << endl;
	return false;
}



bool TicTacBoard::IsRowMade()
{
	int numX, numO, sequence = 4;
	for (unsigned int i = 0; i < width; i++)
	{
		numX = 0, numO = 0;
		for (unsigned int j = 0; j < length; j++)
		{
			if (cells[i][j] == CellType_O)
			{
				numO++;
				numX = 0;
			}
			if (cells[i][j] == CellType_X)
			{
				numX++;
				numO = 0;
			}
			if (cells[i][j] == CellType_Empty)
				numX = 0, numO = 0;
			if ((numX == sequence) || (numO == sequence))
			{
				bVictory = true;
				return true;
			}
		}
	}
	return false;
}


bool TicTacBoard::IsColumnMade()
{
	int numX, numO, sequence = 4;
	for (unsigned int j = 0; j < length; j++)
	{
		numX = 0, numO = 0;
		for (unsigned int i = 0; i < width; i++)
		{
			if (cells[i][j] == CellType_O)
			{
				numO++;
				numX = 0;
			}
			if (cells[i][j] == CellType_X)
			{
				numX++;
				numO = 0;
			}
			if (cells[i][j] == CellType_Empty)
				numX = 0, numO = 0;
			if ((numX == sequence) || (numO == sequence))
			{
				bVictory = true;
				return true;
			}
		}
	}
	return false;
}


bool TicTacBoard::IsDiagMade()
{
	int numX, numO, sequence = 4;
	int j0 = 0 - (int)width + 1, j1 = length + width - 1;
	for (int j = j0; j <= j1; j++)
	{
		numX = 0, numO = 0;
		for (int i = 0; i < width; i++)
		{
			if (i + j >= 0 && i + j < length)
			{
				if (cells[i][i + j] == CellType_O)
				{
					numO++;
					numX = 0;
				}
				if (cells[i][i + j] == CellType_X)
				{
					numX++;
					numO = 0;
				}
				if (cells[i][i + j] == CellType_Empty)
					numX = 0, numO = 0;
				if ((numX == sequence) || (numO == sequence))
				{
					bVictory = true;
					return true;
				}
			}
		}


		numX = 0, numO = 0;
		for (int i = 0; i < width; i++)
		{
			if (j + width - i - 1 >= 0 && j + width - i - 1 < length)
			{
				if (cells[i][j + width - i - 1] == CellType_O)
				{
					numO++;
					numX = 0;
				}
				if (cells[i][j + width - i - 1] == CellType_X)
				{
					numX++;
					numO = 0;
				}
				if (cells[i][j + width - i - 1] == CellType_Empty)
					numX = 0, numO = 0;
				if ((numX == sequence) || (numO == sequence))
				{
					bVictory = true;
					return true;
				}

			}
		}
	}

	return false;
}


bool TicTacBoard::IsBoardFull()
{
	for (unsigned int i = 0; i < width; i++)
		for (unsigned int j = 0; j < length; j++)
			if (cells[i][j] == CellType_Empty)
				return false;
	bVictory = false;
	return true;
}


bool TicTacBoard::CheckEndCondition()
{
	if (IsRowMade() || IsColumnMade() || IsBoardFull() || IsDiagMade())
		return true;
	return false;
}


bool TicTacBoard::IsVictory()
{
	return bVictory;
}