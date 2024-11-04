#include <iostream>
using namespace std;

struct Array
{
    int size;
    int arr[10];
    int length;
};

// Finding Minimum and Maximum in Single Scan
void findMinMax(Array A)
{
    int min, max;
    min = max = A.arr[0];
    for (int i = 0; i < A.length; i++)
    {
        if (A.arr[i] < min)
            min = A.arr[i];
        else if (A.arr[i] > max)
            max = A.arr[i];
    }
    cout << "Max: " << max << endl
         << "Min: " << min;
}

int main()
{
    Array A = {10, {12, 3, 5, 6, 2, 32, 38, 2}, 8};
    findMinMax(A);
    return 0;
}