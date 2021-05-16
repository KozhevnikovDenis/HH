#include <iostream> //библиотека для ввода-вывода
#include <windows.h> //подключаем библиотеку windows.h
int g_nIndex = 0; //создание переменной для работы с массивом
const int MAX_TIMES = 1000; //размер массива данных
DWORD g_dwTimes[MAX_TIMES]; //создание массива, с которым работают потоки
HANDLE g_hMutex = NULL; // переменная для создания мьютекса
DWORD  dwThreadID; // ID потока
int array1[500], array2[500];
static DWORD WINAPI FirstThread(void* pv) //Функция FirstThread для работы с потоком (static - сохраняет значение во время работы программы)
{
	int i = 0;
	BOOL fDone = FALSE; //переменная, работает с циклом, когда FALSE
	while (!fDone) //запуск цикла, работает пока fDone = FALSE
	{
		::WaitForSingleObject(g_hMutex, INFINITE); /*g_hMutex,  ID объекта
			INFINITE время ожидания в миллисекундах
			WaitForSingleObject ждём появление потока, потом Mutex  блокирует доступ другим потокам*/
		if (g_nIndex >= MAX_TIMES) //когда переменная больше (1000)
			fDone = TRUE; //выходим из цикла
		else // или
		{
			g_dwTimes[g_nIndex] = rand() % 1000; //заполняется массив временем с начала работы системы
			array1[i] = g_dwTimes[g_nIndex];
			std::cout << "FirstThread " << g_dwTimes[g_nIndex] << std::endl; // Вывожу текущее значение для первого потока 
			g_nIndex++;
			i++;
		}
		::ReleaseMutex(g_hMutex); //Освобождаем Mutex
	}
	return 0; //выход из функции FirstThread
}
static DWORD WINAPI SecondThread(void* pv) //Функция SecondThread для работы с потоком (static - сохраняет значение во время работы программы
{
	int i = 0;
	BOOL fDone = FALSE; //переменная, работает с циклом, когда FALSE
	while (!fDone) //запуск цикла, работает пока fDone = FALSE
	{
		::WaitForSingleObject(g_hMutex, INFINITE); /*g_hMutex,  ID объекта
			INFINITE время ожидания в миллисекундах
			WaitForSingleObject ждём появление потока, потом Mutex  блокирует доступ другим потокам*/
		if (g_nIndex >= MAX_TIMES) //когда переменная больше (1000)
			fDone = TRUE; //выходим из цикла
		else // или
		{
			g_dwTimes[g_nIndex] = g_dwTimes[g_nIndex - 1] + 123; //заполняется массив временем с начала работы системы
			array2[i] = g_dwTimes[g_nIndex];
			std::cout << "SecondThread " << g_dwTimes[g_nIndex] << std::endl; // Вывожу текущее значение для первого потока 
			g_nIndex++;
			i++;
		}
		::ReleaseMutex(g_hMutex); //Освобождаем Mutex
	}
	return 0;
}
int main(int argc, char* argv[]) //главная функция для работы с потоком
{

	HANDLE hThreads[2]; //создание массива типа HANDLE (любой тип данных)
	g_hMutex = ::CreateMutex(NULL, FALSE, NULL); //Создаем Mutex, атрибут безопастности, флаг начального владельца, имя объекта
	hThreads[0] = ::CreateThread(NULL, 0, FirstThread, NULL, 0,
		&dwThreadID); /*создание первого потока (дескриптор безопасности (по умолчанию - NULL),
									  размер стека в байтах (по умолчанию - 0),
									  указатель на процедуру (с которого начинается выполнение потока),
									  аргумент с предыдущего потока,
									  флаг, записать dwThreadID созданного потока)*/
	hThreads[1] = ::CreateThread(NULL, 0, SecondThread, NULL,
		0, &dwThreadID); /*создание первого потока (дескриптор безопасности (по умолчанию - NULL),
									  размер стека в байтах (по умолчанию - 0),
									  указатель на процедуру (с которого начинается выполнение потока),
									  аргумент с предыдущего потока,
									  флаг, записать dwThreadID созданного потока)*/
	::WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);  // (кол-во ожидаемых объектов, тип ожидаемых объектов, ожидать все объекты, максимальное время ожидания)
	
	double array_divided[500];
	for (int i = 0; i < 500; i++)
	{
		array_divided[i] = (double)array1[i] / array2[i];
		std::cout << "First thread divided by second thread = " << array_divided[i] << std::endl;
	}

	::CloseHandle(hThreads[0]); // закрываем первый поток
	::CloseHandle(hThreads[1]); // закрываем второй поток
	::CloseHandle(g_hMutex); // закрываем Mutex

	return 0;
}