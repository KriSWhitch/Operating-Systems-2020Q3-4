/*
1.	Разработайте приложение на С++, main-функция которого, запускает два независимых процесса A и В.
2.	Процесс А вычисляет факториальную функцию с заданным значением аргумента. +
3.	Процесс В вычисляет сумму заданного количества  чисел Фибоначчи. +
4.	Подберите аргументы функция таким образом, чтобы процесс  A выполнялся примерно 10000 процессорных тиков, а процесс B примерно 20000 процессорных тиков. +
5.	С помощью стандартных функций измерьте реальное время выполнения каждого процесса и всего приложения. +
6.	Объясните полученные результаты.*/

#include <iostream>
#include <ctime>
#include <windows.h>
#include "string.h"
using namespace std;

long double factorial(long double N) {
    Sleep(100);
    if (N < 0) // если пользователь ввел отрицательное число
        return 0; // возвращаем ноль
    if (N == 0) // если пользователь ввел ноль,
        return 1; // возвращаем факториал от нуля - не удивляетесь, но это 1 =)
    else // Во всех остальных случаях
        return N * factorial(N - 1); // делаем рекурсию.
}



int main()
{
    STARTUPINFO cif;
    ZeroMemory(&cif, sizeof(STARTUPINFO));
    PROCESS_INFORMATION pi;
    TCHAR buf[] = TEXT("mspaint.exe");
    if (!(CreateProcess(NULL, buf, NULL, NULL, FALSE, 0,
        NULL, NULL, &cif, &pi)))
        std::wcout << "Error " << '\n';
    getchar();

    return 0;

    clock_t t1, t2, t3, t4;
    t3 = clock();
    t1 = clock();
    
    t2 = clock();
    cout << "Time: " << t2 - t1 << " ticks" << endl; 
    cout << "Time: " << (t2 - t1) / CLOCKS_PER_SEC << " seconds" << endl;
    t1 = clock();
    cout << "Factorial Result: " << factorial(100) << endl;
    t2 = clock();
    cout << "Time: " << t2 - t1 << " ticks" << endl;
    cout << "Time: " << (t2 - t1) / CLOCKS_PER_SEC << " seconds" << endl;
    t4 = clock();
    cout << "Total Time: " << (t4 - t3) / CLOCKS_PER_SEC << " seconds" << endl;

}
