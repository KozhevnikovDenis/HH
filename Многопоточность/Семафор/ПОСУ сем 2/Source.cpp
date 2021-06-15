#include <iostream> 
#include <time.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <windows.h> 
using namespace std;
#ifdef _DEBUG 
#define new DEBUG_NEW 
#undef THIS_FILEstatic char THIS_FILE[] = __FILE__; 
#endif 
using namespace std; static DWORD WINAPI FirstThread(void* pv); // Прототипы функций 
static DWORD WINAPI SecondThread(void* pv); // которые будут участвовать в гонке <designtimesp=21150> потоков 
HANDLE g_hSemaphore; // Обьявляем Хендл семафора 
HANDLE hStdout; // Хендл вывода информации в консоли 
int Lid = 0, g_nIndex = 0; // Флаг, определяющий поток завершённый первым(лидерство), количество синхронизируемых потоков 
int a[10], IndexResours = 0; // Общий ресурс и его индекс 
LONG MaxCount = 3; // Максимальное количество синхронизируемых семафором потоков 


static DWORD WINAPI FirstThread(void* pv)

{
	COORD pos; // Переменная, которая будет хранить текущую координату курсора 
	pos.X = 3; // Столбец отображения значений первого потока 
	BOOL fDone = FALSE; // Флаг отработки потока 
	while (!fDone)
	{
		::WaitForSingleObject(g_hSemaphore, INFINITE); // Ожидание запуска семафора на длительном интервале времени 
		if (g_nIndex >= MaxCount) // Проверяю, не создано ли потоков больше чем максимальное кол-во потоков 
			fDone = TRUE;
		else
		{
			g_nIndex++; // Количество потоков увеличиваю на 1 
			for (int i = 0; i <= 10; i++) // Начинаю цикл для инициализации массива 
			{

				IndexResours++;

				a[IndexResours - 1] = rand() % 200; // Генерирую значения 

				pos.Y = i;
				SetConsoleCursorPosition(hStdout, pos); // Устанавливаю курсор в i - тую строку 
				printf(" %d ", a[IndexResours - 1]); // Выводим значения
				
				Sleep(a[IndexResours - 1]); // Осуществляю задерку 


			}
		}
		::ReleaseSemaphore(g_hSemaphore, 1, 0); // Освобождаю семафор от данного потока 
	}
	return 0;
}
static DWORD WINAPI SecondThread(void* pv)
{
	COORD pos; // Переменная, которая будет хранить текущую координату курсора // Массив задержек второго потока 
	pos.X = 25; // Столбец отображения значений второго потока 
	BOOL fDone = FALSE; // Флаг отработки потока 
	while (!fDone)
	{
		::WaitForSingleObject(g_hSemaphore, INFINITE); // Ожидание запуска семафора на длительном интервале времени 
		if (g_nIndex >= MaxCount) // Проверяю, не создано ли потоков больше чем максимальное кол-во потоков 
			fDone = TRUE;
		else
		{
			g_nIndex++; // Количество потоков увеличиваю на 1 
			for (int i = 0; i <= 10; i++) // Начинаю цикл для инициализации массива 
			{
				IndexResours++;

				a[IndexResours - 1] = i + 1; // заполняем массив значениями 
				pos.Y = i;
				SetConsoleCursorPosition(hStdout, pos); // Устанавливаю курсор в i - тую строку // Выводим значения 
				printf(" %d ", a[IndexResours - 1]); // Выводим значения 

				Sleep(100);

			}
		}
		::ReleaseSemaphore(g_hSemaphore, 1, 0); // Освобождаю семафор от данного потока 
	}
	return 0;
}
static DWORD WINAPI FirstThread1(void* pv)
{
	COORD pos; // Переменная, которая будет хранить текущую координату курсора 
	pos.X = 50; // Столбец отображения значений третьего потока 
	BOOL fDone = FALSE; // Флаг отработки потока 
	while (!fDone)
	{
		::WaitForSingleObject(g_hSemaphore, INFINITE); // Ожидание запуска семафора на длительном интервале времени 
		if (g_nIndex >= MaxCount)
			fDone = TRUE;
		else
		{
			g_nIndex++; // Количество потоков увеличиваю на 1 
			for (int i = 0; i <= 10; i++) // Начинаю цикл для инициализации массива 
			{
				IndexResours++;
				a[IndexResours - 1] = i + 3; // заполняем массив значениями 
				pos.Y = i;
				SetConsoleCursorPosition(hStdout, pos); // Устанавливаю курсор в i - тую строку 
				printf(" %d ", a[IndexResours - 1]); // Выводим значения 

				Sleep(100);

			}
		}
		::ReleaseSemaphore(g_hSemaphore, 1, 0); // Освобождаю семафор от данного потока 
	}
	return 0;
}

int main(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE); // дискриптор 
	{
		DWORD dw; // Обьект синхронизации 
		LONG g_iCount = 3; // начальное значение семафора 
		HANDLE hThreads[3]; // Массив Хендлов потоков 
		g_hSemaphore = ::CreateSemaphore(NULL, g_iCount, MaxCount,
			NULL); // Создаем семафор и инициализируем его Хендл 
		hThreads[0] = ::CreateThread(NULL, 0, FirstThread, NULL, 0, &dw); // Создаем потоки 
		hThreads[1] = ::CreateThread(NULL, 0, SecondThread, NULL, 0, &dw); // и инициализируем Массив Хендлов потоков 
		hThreads[2] = ::CreateThread(NULL, 0, FirstThread1, NULL, 0, &dw);
		::ResumeThread(hThreads[0]); //Запускаем потоки 
		::ResumeThread(hThreads[1]);
		::ResumeThread(hThreads[2]);
		::WaitForMultipleObjects(3, hThreads, TRUE, INFINITE); // Ожидаем окончание работы 3 потоков на очень длительном интервале времени
		::CloseHandle(hThreads[0]); // Закрываем созданные потоки 
		::CloseHandle(hThreads[1]);
		::CloseHandle(hThreads[2]);
		::CloseHandle(g_hSemaphore); // и сам семафор 

		cout << "\n";
		system("pause"); 
		system("cls");
	}
	return 0;
}