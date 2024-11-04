#include <iostream>
using namespace std;

// Left shifting of array
void leftShift(int a[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        a[i] = a[i + 1];
    }
    a[length - 1] = 0;
}

// Left rotation of array
void leftRotate(int a[], int length)
{
    int temp = a[0];
    for (int i = 0; i < length - 1; i++)
    {
        a[i] = a[i + 1];
    }
    a[length - 1] = temp;
}

// Right rotation of array
void rightRotate(int a[], int length)
{
    int temp = a[length - 1];
    for (int i = length - 1; i > 0; i--)
    {
        a[i] = a[i - 1];
    }
    a[0] = temp;
}

int main()
{
    int a[] = {1, 2, 4, 5, 6};
    int length = 5;
    rightRotate(a, length);
    rightRotate(a, length);

    for (int x : a)
    {
        cout << x << endl;
    }
}