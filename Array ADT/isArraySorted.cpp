#include <iostream>
using namespace std;

struct Array
{
    int size;
    int length;
    int A[10];
};

bool isSorted(Array* arr)
{
    for(int i=0; i<arr->length-1;i++)
    {
        if(arr->A[i] > arr->A[i+1])
            return false;
    }
    return true;
}

int main()
{
    Array arr = {10,5,{1,2,4,5,7}};
    cout<<isSorted(&arr);
    return 0;
}