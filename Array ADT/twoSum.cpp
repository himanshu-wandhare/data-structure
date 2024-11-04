#include <iostream>
using namespace std;

struct Array
{
    int size;
    int arr[10];
    int length;
};

int findMax(Array A)
{
    int max = A.arr[0];
    for (int i = 0; i < A.length; i++)
    {
        if (A.arr[i] > max)
            max = A.arr[i];
    }
    return max;
}

// Finding a pair with sum K using nested loops          Time: O(n^2)
void findPairOfSumK(Array A, int k)
{
    for (int i = 0; i < A.length - 1; i++)
    {
        for (int j = i + 1; j < A.length; j++)
        {
            if (A.arr[i] + A.arr[j] == k)
                cout << endl
                     << A.arr[i] << " + " << A.arr[j] << " = " << k;
        }
    }
}

// Finding pair with sum K using hashing table
void findPairUsingHash(Array A, int k)
{
    int size = findMax(A) + 1;
    int H[size] = {0};
    for (int i = 0; i < A.length; i++)
    {
        if (H[k - A.arr[i]] != 0)
            cout << A.arr[i] << "+" << k - A.arr[i] << "=" << k;
        H[A.arr[i]]++;
    }
}

// Finding pair of sum K in sorted array(Two pointer approach)
// Time Complexity: O(n)
void pairInSortedArray(Array A, int k)
{
    int i = 0, j = A.length - 1;
    while (i < j)
    {
        if (A.arr[i] + A.arr[j] == k)
            cout << endl
                 << A.arr[i++] << "+" << A.arr[j--] << "=" << k;
        else if (A.arr[i] + A.arr[j] < k)
            i++;
        else
            j--;
    }
}

int main()
{
    Array A = {10, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10};
    int k = 10;
    // findPairOfSumK(A, k);
    // findPairUsingHash(A, k);
    pairInSortedArray(A, k);
    return 0;
}