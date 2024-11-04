#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n = 1010;
    int p = 1;
    int sum = 0;
    while (n > 0)
    {
        int lastDg = n % 10;
        sum += lastDg * p;
        p = p * 2;
        n /= 10;
    }
    cout << sum;
}