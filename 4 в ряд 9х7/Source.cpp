#include "TicTacBoard.h"
#include "pch.h"
#include "TicTacManager.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    TicTacManager manager;
    if (!manager.Init())
    {
        cout << "�������� ������, �������...";
        _getch();
        return 0;
    }
    while (!manager.IsGameFinished())
    {
        manager.MakeMove();
    }
    _getch;
}