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
    clock_t t1, t2;
    t1 = clock();
    cout << "Fibonachi Result: " << fib(41) << endl;
    t2 = clock();
    cout << "Time: " << t2 - t1 << " ticks" << endl;
    cout << "Time: " << (t2 - t1) / CLOCKS_PER_SEC << " seconds" << endl;
}
