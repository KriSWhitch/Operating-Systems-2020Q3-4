/*
1.	Разработайте приложение на С++, main-функция которого, запускает два независимых потока A и В.
2.	Поток А вычисляет факториальную функцию с заданным значением аргумента.+
3.	Поток В вычисляет сумму заданного количества  чисел Фибоначчи.+
4.	Подберите аргументы функция таким образом, чтобы поток  A выполнялся примерно 10000 процессорных тиков, а поток B примерно 20000 процессорных тиков.+
5.	Примерно каждые 1000 процессорных тиков потоки должны осуществлять вывод сообщения в поток.
6.	С помощью стандартных функций измерьте реальное время выполнения каждого потока и всего приложения.
7.	Объясните полученные результаты.*/

#include <iostream>
#include <ctime>
#include <windows.h>
#include "string.h"
using namespace std;

int main()
{
    clock_t t1, t2, t3, t4;
    t3 = clock();
    t1 = clock();
    STARTUPINFO si1;
    ZeroMemory(&si1, sizeof(si1));
    si1.wShowWindow = SW_HIDE;
    si1.dwFlags = STARTF_USESHOWWINDOW;
    PROCESS_INFORMATION pi1;
    bool bp1 = CreateProcess(L"F:\\Университет\\2k1s\\ОСМУ\\lab1\\Debug\\Fibonachi.exe", 0, 0, 0, FALSE, 0, NULL, NULL, &si1, &pi1);
    if (bp1) WaitForSingleObject(pi1.hProcess, INFINITE);
    CloseHandle(pi1.hProcess);
    CloseHandle(pi1.hThread);
    t2 = clock();
    cout << "Time: " << t2 - t1 << " ticks" << endl;
    cout << "Time: " << (t2 - t1) / CLOCKS_PER_SEC << " seconds" << endl;
    t1 = clock();
    STARTUPINFO si2;
    ZeroMemory(&si2, sizeof(si2));
    si2.wShowWindow = SW_HIDE;
    si2.dwFlags = STARTF_USESHOWWINDOW;
    PROCESS_INFORMATION pi2;
    bool bp2 = CreateProcess(L"F:\\Университет\\2k1s\\ОСМУ\\lab1\\Debug\\Factorial.exe", 0, 0, 0, FALSE, 0, NULL, NULL, &si2, &pi2);
    if (bp2) WaitForSingleObject(pi2.hProcess, INFINITE);
    CloseHandle(pi2.hProcess);
    CloseHandle(pi2.hThread);
    t2 = clock();
    cout << "Time: " << t2 - t1 << " ticks" << endl;
    cout << "Time: " << (t2 - t1) / CLOCKS_PER_SEC << " seconds" << endl;
    t4 = clock();
    cout << "Total Time: " << (t4 - t3) / CLOCKS_PER_SEC << " seconds" << endl;
}
