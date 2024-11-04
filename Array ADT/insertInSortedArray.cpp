#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int length;
    int size;
};

void insert(Array* arr, int x)
{
    if(arr->length < arr->size)
    {
        int i;
        for(i =arr->length-1;i>=0 && arr->A[i]>x; i--)
            arr->A[i+1] = arr->A[i];
        arr->A[i+1] = x;
    }
}

int main()
{
    Array arr = {{12,13,20,24,35},5,10};
    insert(&arr,11);
    for(int i=0;i<arr.length;i++)
        cout<<arr.A[i]<<" ";
    return 0;
}