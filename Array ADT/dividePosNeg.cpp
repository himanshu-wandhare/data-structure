#include <iostream>
using namespace std;

struct Array
{
    int size;
    int A[15];
    int length;
};

void rearrange(Array *arr)
{
    int i = 0;
    int j = arr->length-1;
    int temp;
    while(i<j)
    {
        while(arr->A[i]<0) i++;
        while(arr->A[j]>=0) j--;

        if(i<j)
        {
            temp = arr->A[i];
            arr->A[i] = arr->A[j];
            arr->A[j] = temp;
        }
    }
}

int main()
{
    Array arr = {10, {-2,2,-3,4,5,2,-1,-8,2,-5,9},11};
    rearrange(&arr);
    for(int i=0; i<arr.length; i++)
        cout<<arr.A[i]<< " ";
    return 0;
}