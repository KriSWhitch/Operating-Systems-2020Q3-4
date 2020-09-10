
#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

long double factorial(long double N) {
    if (N < 0) // если пользователь ввел отрицательное число
        return 0; // возвращаем ноль
    if (N == 0) // если пользователь ввел ноль,
        return 1; // возвращаем факториал от нуля - не удивляетесь, но это 1 =)
    else // Во всех остальных случаях
        return N * factorial(N - 1); // делаем рекурсию.
}

int main()
{
    clock_t t1, t2;
    t1 = clock();
    cout << "Factorial Result: " << factorial(11) << endl;
    t2 = clock();
    cout << "Time: " << (t2 - t1) * 10000 << " ticks" << endl;
    cout << "Time: " << (t2 - t1) << " ms" << endl;
}

