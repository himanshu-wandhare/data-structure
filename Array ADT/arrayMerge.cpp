#include <iostream>
using namespace std;

class Array
{
    int size;
    int *arr;
    int length;
public:
    Array();
    ~Array();
    void append(int);
    void display();
    Array* merge(Array);
};

Array::Array()
{
    size = 10;
    arr = new int[size];
    length = 0;
}

Array::~Array()
{
    delete []arr;
}

void Array::append(int x)
{
    if(length<size)
        arr[length++] = x;
}

void Array::display()
{
    for(int i = 0; i<length; i++)
        cout<<arr[i]<<" ";
}

Array* Array::merge(Array B)
{
    int i,j,k;
    i=j=k=0;
    Array *C = new Array;
    while(i < length && j < B.length)
    {
        if(arr[i] < B.arr[j])
        {
            C->arr[k++] = arr[i++];
        }
        else
        {
            C->arr[k++] = B.arr[j++];
        }
    }
    while(i<length)
        C->arr[k++] = arr[i++];
    while(j<B.length)
        C->arr[k++] = B.arr[j++];
    C->length = length + B.length;
    return C;
}

int main()
{
    Array A;
    A.append(3);
    A.append(7);
    A.append(8);
    A.append(9);
    A.append(12);
    A.display();
    cout<<endl;

    Array B;
    B.append(3);
    B.append(6);
    B.append(7);
    B.display();
    cout<<endl;

    Array *C;
    C = A.merge(B);
    C->display();


    return 0;
}
