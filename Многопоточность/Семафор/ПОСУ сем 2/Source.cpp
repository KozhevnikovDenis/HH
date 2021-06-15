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
using namespace std; static DWORD WINAPI FirstThread(void* pv); // ��������� ������� 
static DWORD WINAPI SecondThread(void* pv); // ������� ����� ����������� � ����� <designtimesp=21150> ������� 
HANDLE g_hSemaphore; // ��������� ����� �������� 
HANDLE hStdout; // ����� ������ ���������� � ������� 
int Lid = 0, g_nIndex = 0; // ����, ������������ ����� ����������� ������(���������), ���������� ���������������� ������� 
int a[10], IndexResours = 0; // ����� ������ � ��� ������ 
LONG MaxCount = 3; // ������������ ���������� ���������������� ��������� ������� 


static DWORD WINAPI FirstThread(void* pv)

{
	COORD pos; // ����������, ������� ����� ������� ������� ���������� ������� 
	pos.X = 3; // ������� ����������� �������� ������� ������ 
	BOOL fDone = FALSE; // ���� ��������� ������ 
	while (!fDone)
	{
		::WaitForSingleObject(g_hSemaphore, INFINITE); // �������� ������� �������� �� ���������� ��������� ������� 
		if (g_nIndex >= MaxCount) // ��������, �� ������� �� ������� ������ ��� ������������ ���-�� ������� 
			fDone = TRUE;
		else
		{
			g_nIndex++; // ���������� ������� ���������� �� 1 
			for (int i = 0; i <= 10; i++) // ������� ���� ��� ������������� ������� 
			{

				IndexResours++;

				a[IndexResours - 1] = rand() % 200; // ��������� �������� 

				pos.Y = i;
				SetConsoleCursorPosition(hStdout, pos); // ������������ ������ � i - ��� ������ 
				printf(" %d ", a[IndexResours - 1]); // ������� ��������
				
				Sleep(a[IndexResours - 1]); // ����������� ������� 


			}
		}
		::ReleaseSemaphore(g_hSemaphore, 1, 0); // ���������� ������� �� ������� ������ 
	}
	return 0;
}
static DWORD WINAPI SecondThread(void* pv)
{
	COORD pos; // ����������, ������� ����� ������� ������� ���������� ������� // ������ �������� ������� ������ 
	pos.X = 25; // ������� ����������� �������� ������� ������ 
	BOOL fDone = FALSE; // ���� ��������� ������ 
	while (!fDone)
	{
		::WaitForSingleObject(g_hSemaphore, INFINITE); // �������� ������� �������� �� ���������� ��������� ������� 
		if (g_nIndex >= MaxCount) // ��������, �� ������� �� ������� ������ ��� ������������ ���-�� ������� 
			fDone = TRUE;
		else
		{
			g_nIndex++; // ���������� ������� ���������� �� 1 
			for (int i = 0; i <= 10; i++) // ������� ���� ��� ������������� ������� 
			{
				IndexResours++;

				a[IndexResours - 1] = i + 1; // ��������� ������ ���������� 
				pos.Y = i;
				SetConsoleCursorPosition(hStdout, pos); // ������������ ������ � i - ��� ������ // ������� �������� 
				printf(" %d ", a[IndexResours - 1]); // ������� �������� 

				Sleep(100);

			}
		}
		::ReleaseSemaphore(g_hSemaphore, 1, 0); // ���������� ������� �� ������� ������ 
	}
	return 0;
}
static DWORD WINAPI FirstThread1(void* pv)
{
	COORD pos; // ����������, ������� ����� ������� ������� ���������� ������� 
	pos.X = 50; // ������� ����������� �������� �������� ������ 
	BOOL fDone = FALSE; // ���� ��������� ������ 
	while (!fDone)
	{
		::WaitForSingleObject(g_hSemaphore, INFINITE); // �������� ������� �������� �� ���������� ��������� ������� 
		if (g_nIndex >= MaxCount)
			fDone = TRUE;
		else
		{
			g_nIndex++; // ���������� ������� ���������� �� 1 
			for (int i = 0; i <= 10; i++) // ������� ���� ��� ������������� ������� 
			{
				IndexResours++;
				a[IndexResours - 1] = i + 3; // ��������� ������ ���������� 
				pos.Y = i;
				SetConsoleCursorPosition(hStdout, pos); // ������������ ������ � i - ��� ������ 
				printf(" %d ", a[IndexResours - 1]); // ������� �������� 

				Sleep(100);

			}
		}
		::ReleaseSemaphore(g_hSemaphore, 1, 0); // ���������� ������� �� ������� ������ 
	}
	return 0;
}

int main(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE); // ���������� 
	{
		DWORD dw; // ������ ������������� 
		LONG g_iCount = 3; // ��������� �������� �������� 
		HANDLE hThreads[3]; // ������ ������� ������� 
		g_hSemaphore = ::CreateSemaphore(NULL, g_iCount, MaxCount,
			NULL); // ������� ������� � �������������� ��� ����� 
		hThreads[0] = ::CreateThread(NULL, 0, FirstThread, NULL, 0, &dw); // ������� ������ 
		hThreads[1] = ::CreateThread(NULL, 0, SecondThread, NULL, 0, &dw); // � �������������� ������ ������� ������� 
		hThreads[2] = ::CreateThread(NULL, 0, FirstThread1, NULL, 0, &dw);
		::ResumeThread(hThreads[0]); //��������� ������ 
		::ResumeThread(hThreads[1]);
		::ResumeThread(hThreads[2]);
		::WaitForMultipleObjects(3, hThreads, TRUE, INFINITE); // ������� ��������� ������ 3 ������� �� ����� ���������� ��������� �������
		::CloseHandle(hThreads[0]); // ��������� ��������� ������ 
		::CloseHandle(hThreads[1]);
		::CloseHandle(hThreads[2]);
		::CloseHandle(g_hSemaphore); // � ��� ������� 

		cout << "\n";
		system("pause"); 
		system("cls");
	}
	return 0;
}