#include <iostream> //���������� ��� �����-������
#include <windows.h> //���������� ���������� windows.h
int g_nIndex = 0; //�������� ���������� ��� ������ � ��������
const int MAX_TIMES = 1000; //������ ������� ������
DWORD g_dwTimes[MAX_TIMES]; //�������� �������, � ������� �������� ������
HANDLE g_hMutex = NULL; // ���������� ��� �������� ��������
DWORD  dwThreadID; // ID ������
int array1[500], array2[500];
static DWORD WINAPI FirstThread(void* pv) //������� FirstThread ��� ������ � ������� (static - ��������� �������� �� ����� ������ ���������)
{
	int i = 0;
	BOOL fDone = FALSE; //����������, �������� � ������, ����� FALSE
	while (!fDone) //������ �����, �������� ���� fDone = FALSE
	{
		::WaitForSingleObject(g_hMutex, INFINITE); /*g_hMutex,  ID �������
			INFINITE ����� �������� � �������������
			WaitForSingleObject ��� ��������� ������, ����� Mutex  ��������� ������ ������ �������*/
		if (g_nIndex >= MAX_TIMES) //����� ���������� ������ (1000)
			fDone = TRUE; //������� �� �����
		else // ���
		{
			g_dwTimes[g_nIndex] = rand() % 1000; //����������� ������ �������� � ������ ������ �������
			array1[i] = g_dwTimes[g_nIndex];
			std::cout << "FirstThread " << g_dwTimes[g_nIndex] << std::endl; // ������ ������� �������� ��� ������� ������ 
			g_nIndex++;
			i++;
		}
		::ReleaseMutex(g_hMutex); //����������� Mutex
	}
	return 0; //����� �� ������� FirstThread
}
static DWORD WINAPI SecondThread(void* pv) //������� SecondThread ��� ������ � ������� (static - ��������� �������� �� ����� ������ ���������
{
	int i = 0;
	BOOL fDone = FALSE; //����������, �������� � ������, ����� FALSE
	while (!fDone) //������ �����, �������� ���� fDone = FALSE
	{
		::WaitForSingleObject(g_hMutex, INFINITE); /*g_hMutex,  ID �������
			INFINITE ����� �������� � �������������
			WaitForSingleObject ��� ��������� ������, ����� Mutex  ��������� ������ ������ �������*/
		if (g_nIndex >= MAX_TIMES) //����� ���������� ������ (1000)
			fDone = TRUE; //������� �� �����
		else // ���
		{
			g_dwTimes[g_nIndex] = g_dwTimes[g_nIndex - 1] + 123; //����������� ������ �������� � ������ ������ �������
			array2[i] = g_dwTimes[g_nIndex];
			std::cout << "SecondThread " << g_dwTimes[g_nIndex] << std::endl; // ������ ������� �������� ��� ������� ������ 
			g_nIndex++;
			i++;
		}
		::ReleaseMutex(g_hMutex); //����������� Mutex
	}
	return 0;
}
int main(int argc, char* argv[]) //������� ������� ��� ������ � �������
{

	HANDLE hThreads[2]; //�������� ������� ���� HANDLE (����� ��� ������)
	g_hMutex = ::CreateMutex(NULL, FALSE, NULL); //������� Mutex, ������� �������������, ���� ���������� ���������, ��� �������
	hThreads[0] = ::CreateThread(NULL, 0, FirstThread, NULL, 0,
		&dwThreadID); /*�������� ������� ������ (���������� ������������ (�� ��������� - NULL),
									  ������ ����� � ������ (�� ��������� - 0),
									  ��������� �� ��������� (� �������� ���������� ���������� ������),
									  �������� � ����������� ������,
									  ����, �������� dwThreadID ���������� ������)*/
	hThreads[1] = ::CreateThread(NULL, 0, SecondThread, NULL,
		0, &dwThreadID); /*�������� ������� ������ (���������� ������������ (�� ��������� - NULL),
									  ������ ����� � ������ (�� ��������� - 0),
									  ��������� �� ��������� (� �������� ���������� ���������� ������),
									  �������� � ����������� ������,
									  ����, �������� dwThreadID ���������� ������)*/
	::WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);  // (���-�� ��������� ��������, ��� ��������� ��������, ������� ��� �������, ������������ ����� ��������)
	
	double array_divided[500];
	for (int i = 0; i < 500; i++)
	{
		array_divided[i] = (double)array1[i] / array2[i];
		std::cout << "First thread divided by second thread = " << array_divided[i] << std::endl;
	}

	::CloseHandle(hThreads[0]); // ��������� ������ �����
	::CloseHandle(hThreads[1]); // ��������� ������ �����
	::CloseHandle(g_hMutex); // ��������� Mutex

	return 0;
}