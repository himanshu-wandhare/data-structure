#include <iostream>
using namespace std;

struct Array 
{
    int size;
    int length;
    int arr[10];
};

int max(Array A)
{
    int max = A.arr[0];
    for(int i = 0; i < A.length; i++)
    {
        if(A.arr[i] > max)
            max = A.arr[i];
    }
    return max;
}

//Finding duplicate element in Sorted Array
void findDuplicates(Array A)
{
    int duplicate;
    for(int i = 0; i < A.length; i++)
    {
        if(A.arr[i] == A.arr[i+1] && A.arr[i] != duplicate)
        {
            cout << A.arr[i] << " ";
            duplicate = A.arr[i];
        }
    }
}

//Counting duplicate element in sorted array
void countDuplicates(Array A)
{
    int j;
    for(int i = 0; i < A.length; i++)
    {
        if(A.arr[i] == A.arr[i+1])
        {
            j = i + 1;
            while(A.arr[i] == A.arr[j]) j++;
            cout << A.arr[i] << " Appear " << j-i << " times" << endl;
            i = j + 1;
        }
    }
}

//Finding duplicate elemant in unsorted or sorted array using Hash table
void findDuplicateByHash(Array A)
{
    int size = max(A) + 1;
    int H[size] = {0};
    for(int i = 0; i < A.length; i++)
        H[A.arr[i]]++;
    
    for(int i = A.arr[0]; i < size; i++)
    {
        if(H[i] > 1) cout<<i<<" appear "<<H[i]<<"times"<<endl;
    }
}

//Finding duplicate element in Unsorted Array
void findDupInUnsorted(Array A)
{
    int count = 0;
    for(int i = 0; i < A.length - 1; i++)
    {   
        count = 1;
        if(A.arr[i] != -1)
        {
            for(int j = i+1; j < A.length; j++)
            {
                if(A.arr[i] == A.arr[j])
                {
                    count++;
                    A.arr[j] = -1;  
                }
            }
            if(count > 1) cout<<A.arr[i]<<"appear"<<count<<"times"<<endl;
        }
    }
}

int main()
{
    Array A = { 10, 10, {3,6,8,8,10,12,15,15,15,20} };
    // countDuplicates(A);
    // findDuplicates(A);
    // findDuplicateByHash(A);
    findDupInUnsorted(A);
}