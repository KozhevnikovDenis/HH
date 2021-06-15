#include <iostream>
#include <windows.h>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int g_nIndex = 0;
const int MAX_TIMES = 1000;
DWORD g_dwTimes[MAX_TIMES];
CRITICAL_SECTION g_CriticalSection;
int colore1, colore2, colore3, colore4, colore5;


static DWORD WINAPI FirstThread(void* pv)
{
	BOOL fDone = FALSE;	

	while (!fDone)
	{
		::EnterCriticalSection(&g_CriticalSection);
		if (g_nIndex >= MAX_TIMES)
		{
			fDone = TRUE;
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | colore1));
			cout << "Thread No.1 out of 1000!" << endl;
			::LeaveCriticalSection(&g_CriticalSection);
			break;
		}
		else
		{
			g_dwTimes[g_nIndex] = ::GetTickCount();
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | colore1));
			cout << "Thread No.1 output: " << g_dwTimes[g_nIndex] << endl;
			g_nIndex++;
		}
		::LeaveCriticalSection(&g_CriticalSection);
	}
	return 0;
}
static DWORD WINAPI SecondThread(void* pv)
{
	BOOL fDone = FALSE;

	while (!fDone)
	{
		::EnterCriticalSection(&g_CriticalSection);
		if (g_nIndex >= MAX_TIMES)
		{
			fDone = TRUE;
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | colore2));
			cout << "Thread No.2 out of 1000!" << endl;
			::LeaveCriticalSection(&g_CriticalSection);
			break;
		}
		else
		{
			g_dwTimes[g_nIndex] = ::GetTickCount();
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | colore2));
			cout << "Thread No.2 output: " << g_dwTimes[g_nIndex] << endl;
			g_nIndex++;
		}
		::LeaveCriticalSection(&g_CriticalSection);
	}
	return 0;
}
static DWORD WINAPI ThirdThread(void* pv)
{
	BOOL fDone = FALSE;

	while (!fDone)
	{
		::EnterCriticalSection(&g_CriticalSection);
		if (g_nIndex >= MAX_TIMES)
		{
			fDone = TRUE;
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | colore3));
			cout << "Thread No.3 out of 1000!" << endl;
			::LeaveCriticalSection(&g_CriticalSection);
			break;
		}
		else
		{
			g_dwTimes[g_nIndex] = ::GetTickCount();
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | colore3));
			cout << "Thread No.3 output: " << g_dwTimes[g_nIndex] << endl;
			g_nIndex++;
		}
		::LeaveCriticalSection(&g_CriticalSection);
	}
	return 0;
}
static DWORD WINAPI FourthThread(void* pv)
{
	BOOL fDone = FALSE;

	while (!fDone)
	{
		::EnterCriticalSection(&g_CriticalSection);
		if (g_nIndex >= MAX_TIMES)
		{
			fDone = TRUE;
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | colore4));
			cout << "Thread No.4 out of 1000!" << endl;
			::LeaveCriticalSection(&g_CriticalSection);
			break;
		}
		else
		{
			g_dwTimes[g_nIndex] = ::GetTickCount();
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | colore4));
			cout << "Thread No.4 output: " << g_dwTimes[g_nIndex] << endl;
			g_nIndex++;
		}
		::LeaveCriticalSection(&g_CriticalSection);
	}
	return 0;
}
static DWORD WINAPI FifthThread(void* pv)
{
	BOOL fDone = FALSE;

	while (!fDone)
	{
		::EnterCriticalSection(&g_CriticalSection);
		if (g_nIndex >= MAX_TIMES)
		{
			fDone = TRUE;
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | colore5));
			cout << "Thread No.5 out of 1000!" << endl;
			::LeaveCriticalSection(&g_CriticalSection);
			break;
		}
		else
		{
			g_dwTimes[g_nIndex] = ::GetTickCount();
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | colore5));
			cout << "Thread No.5 output: " << g_dwTimes[g_nIndex] << endl;
			g_nIndex++;
		}
		::LeaveCriticalSection(&g_CriticalSection);
	}
	return 0;
}


int main(int argc, char* argv[])
{
	srand(GetTickCount());
	colore1 = rand() % 15;
	colore2 = rand() % 15;
	colore3 = rand() % 15;
	colore4 = rand() % 15;
	colore5 = rand() % 15;


	HANDLE hThreads[5];
	::InitializeCriticalSection(&g_CriticalSection);

	DWORD dwThreadID;
	hThreads[0] = ::CreateThread(NULL, 0, FirstThread, &dwThreadID, 0, &dwThreadID);
	hThreads[1] = ::CreateThread(NULL, 0, SecondThread, &dwThreadID, 0, &dwThreadID);
	hThreads[2] = ::CreateThread(NULL, 0, ThirdThread, &dwThreadID, 0, &dwThreadID);
	hThreads[3] = ::CreateThread(NULL, 0, FourthThread, &dwThreadID, 0, &dwThreadID);
	hThreads[4] = ::CreateThread(NULL, 0, FifthThread, &dwThreadID, 0, &dwThreadID);


	// ждем завершения обоих потоков
	::WaitForMultipleObjects(5, hThreads, TRUE, INFINITE);

	// закрываем описатели потоков
	::CloseHandle(hThreads[0]);
	::CloseHandle(hThreads[1]);
	::CloseHandle(hThreads[2]);
	::CloseHandle(hThreads[3]);
	::CloseHandle(hThreads[4]);

	::DeleteCriticalSection(&g_CriticalSection);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
	return 0;
}