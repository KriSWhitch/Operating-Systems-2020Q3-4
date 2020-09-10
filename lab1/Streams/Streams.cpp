/*
1.	Разработайте приложение на С++, main-функция которого, запускает два независимых потока A и В. +
2.	Поток А вычисляет факториальную функцию с заданным значением аргумента.+
3.	Поток В вычисляет сумму заданного количества  чисел Фибоначчи.+
4.	Подберите аргументы функция таким образом, чтобы поток  A выполнялся примерно 10000 процессорных тиков, а поток B примерно 20000 процессорных тиков.+
5.	Примерно каждые 1000 процессорных тиков потоки должны осуществлять вывод сообщения в поток. +
6.	С помощью стандартных функций измерьте реальное время выполнения каждого потока и всего приложения. +
7.	Объясните полученные результаты.*/

#include <ctime>
#include <windows.h>
#include <iostream>
#include "string.h"
using namespace std;

bool should_stop = true;

int fib(int i) {
	int value = 0;
	if (i < 1) return 0;
	if (i == 1) return 1;
	return fib(i - 1) + fib(i - 2);
}

long double factorial(long double N) {
	if (N < 0) // если пользователь ввел отрицательное число
		return 0; // возвращаем ноль
	if (N == 0) // если пользователь ввел ноль,
		return 1; // возвращаем факториал от нуля - не удивляетесь, но это 1 =)
	else // Во всех остальных случаях
		return N * factorial(N - 1); // делаем рекурсию.
}

DWORD WINAPI myThread3(LPVOID t)
{
	int timer = 0;
	const char* str = (const char*)t;
	while (true) {
		timer++;
		Sleep(1000);
		cout << str << timer << " sec" << endl;
	}
	return timer;
}

DWORD WINAPI myThread2(LPVOID t)
{
	clock_t t1, t2;
	DWORD myThreadID;
	const char* str = "Thread 2: ";
	HANDLE myHandle = CreateThread(0, 0, myThread3, (LPVOID)str, 0, &myThreadID);
	t1 = clock();
	long double result;
	result = factorial(5);
	cout << "Factorial Result: " << result << endl;
	t2 = clock();
	cout << "Time: " << (t2 - t1) * 10000 << " ticks" << endl;
	cout << "Time: " << (t2 - t1) << " ms" << endl;
	TerminateThread(myHandle, 0);
	return result;
}



DWORD WINAPI myThread(LPVOID t)
{
	clock_t t1, t2;
	DWORD myThreadID;
	const char* str = "Thread 1: ";
	HANDLE myHandle = CreateThread(0, 0, myThread3, (LPVOID)str, 0, &myThreadID);
	t1 = clock();
	long double result;
	result = fib(20);
	cout << "Fibonachi Result: " << result << endl;
	t2 = clock();
	cout << "Time: " << (t2 - t1) * 10000 << " ticks" << endl;
	cout << "Time: " << (t2 - t1) << " ms" << endl;
	TerminateThread(myHandle, 0);
	return result;
}



int main()
{
	clock_t t1, t2;
	t1 = clock();
	DWORD myThreadID, myThreadID2;
	HANDLE myHandle = CreateThread(0, 0, myThread, 0, 0, &myThreadID);
	HANDLE myHandle2 = CreateThread(0, 0, myThread2, 0, 0, &myThreadID2);
	if (myHandle) WaitForSingleObject(myHandle, INFINITE);
	CloseHandle(myHandle);
	TerminateThread(myHandle, 0);
	if (myHandle2) WaitForSingleObject(myHandle2, INFINITE);
	CloseHandle(myHandle2);
	TerminateThread(myHandle2, 0);
	t2 = clock();
	cout << "Total Time: " << (t2 - t1) << " ms" << endl;
	return 0;
}
