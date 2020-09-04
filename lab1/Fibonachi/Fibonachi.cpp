#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

int fib(int i) {
    int value = 0;
    if (i < 1) return 0;
    if (i == 1) return 1;
    return fib(i - 1) + fib(i - 2);
}

int main()
{
    cout << "Fibonachi Result: " << fib(41) << endl;
}
