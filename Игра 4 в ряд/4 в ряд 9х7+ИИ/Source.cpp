#include "TicTacBoard.h"
#include "pch.h"
#include "TicTacManager.h"
//#include "windows.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    TicTacManager manager;

    if (!manager.Init())
    {
        cout << "Неверные данные, выходим...";
        _getch();
        return 0;
    }
    
    int seed = manager.Seed();
  
    while (!manager.IsGameFinished())
    {  
        srand(seed);
        manager.MakeMove();
    }
    _getch;
}