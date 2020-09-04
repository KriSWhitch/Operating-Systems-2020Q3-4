
#include <iostream>
#include <ctime>
#include <windows.h>
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
    cout << "Factorial Result: " << factorial(100) << endl;
}

