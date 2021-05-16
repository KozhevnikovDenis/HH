#include <Windows.h>
#include <iostream>
#include <conio.h>
using namespace std;


int i = 0;
HANDLE hMutex;


DWORD WINAPI Tread1(LPVOID inParam)
{
	while (i < 1000)
	{
		::WaitForSingleObject(hMutex, INFINITE);
		i++;
		if (i > 1000)
		{
			cout << "Tread No.1: Out of 1000!" << endl;
			::ReleaseMutex(hMutex);
			break;
		}
		cout << "Tread No.1 output: " << i << endl;
		::ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI Tread2(LPVOID inParam)
{
	while (i < 1000)
	{
		::WaitForSingleObject(hMutex, INFINITE);
		i++;
		if (i > 1000)
		{
			cout << "Tread No.2: Out of 1000!" << endl;
			::ReleaseMutex(hMutex);
			break;
		}
		cout << "Tread No.2 output: " << i << endl;
		::ReleaseMutex(hMutex);
	}

	return 0;
}

DWORD WINAPI Tread3(LPVOID inParam)
{
	while (i < 1000)
	{
		::WaitForSingleObject(hMutex, INFINITE);
		i++;
		if (i > 1000)
		{
			cout << "Tread No.3: Out of 1000!" << endl;
			::ReleaseMutex(hMutex);
			break;
		}
		cout << "Tread No.3 output: " << i << endl;
		::ReleaseMutex(hMutex);
	}

	return 0;
}


int main()
{
	setlocale(0, "");
	HANDLE hTread1, hTread2, hTread3;
	hMutex = ::CreateMutex(NULL, FALSE, NULL);

	hTread1 = ::CreateThread(NULL, 0, &(Tread1), NULL, 0, NULL);
	hTread2 = ::CreateThread(NULL, 0, &(Tread2), NULL, 0, NULL);
	hTread3 = ::CreateThread(NULL, 0, &(Tread3), NULL, 0, NULL);

	_getch();

	::CloseHandle(hTread1);
	::CloseHandle(hTread2);
	::CloseHandle(hTread3);
	::CloseHandle(hMutex);
	
	return 0;
}