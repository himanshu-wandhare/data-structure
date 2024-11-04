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
    for(int i = 0; i < A.length; i++)
    {
        if(max < A.arr[i])
            max = A.arr[i];
    }
    return max;
}

//Finding single missing element in sorted array
int findMissingElement(Array A)
{
    int sum = 0;
    int s = (A.arr[A.length-1]*(A.arr[A.length-1]+1))/2;
    for(int i = 0; i < A.length; i++)
        sum += A.arr[i];
    return s-sum;
}

//Finding single missing element starting from any number in sorted array
int findMissingFromAny(Array A)
{
    int l = 0;
    int diff = A.arr[0] - l;
    for(int i = 0; i < A.length; i++)
    {
        if(A.arr[i] - i != diff)
        {
            return i + diff;
        }
    }
}

//Finding Multiple Missing Element from Sorted Array
void findMultipleMissing(Array A)
{
    int diff = A.arr[0] - 0;
    for(int i = 0; i < A.length; i++)
    {
        if(A.arr[i] - i !=  diff)
        {
            while(diff < A.arr[i] - i)
            {
                cout << i + diff << " ";
                diff++;
            }
        }
    }
}

//Finding multiple missing element in array using hash table
void findMissingByHash(Array A)
{
    int size = findMax(A)+1;
    int H[size] = {0};
    for(int i = 0; i < A.length; i++)
        H[A.arr[i]]++;
    
    for(int i = A.arr[0]; i < size; i++)
    {
        if(H[i] == 0)
            cout<<i<<" ";
    }
}

int main()
{
    Array A = {10, {6,7,8,9,11,12,15,16,17,18},10};
    // cout << findMissingElement(A);
    // cout << findMissingFromAny(A);
    // findMultipleMissing(A);
    findMissingByHash(A);
}