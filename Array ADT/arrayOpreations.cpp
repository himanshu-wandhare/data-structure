#include <iostream>
using namespace std;

class Array
{
    int size, length;
    int *A;
    void swap(int, int);

public:
    Array();
    ~Array();
    void display();
    void append(int);
    void insert(int, int);
    void remove(int);
    int get(int);
    void set(int, int);
    int sum();
    int sumRecursive(int);
    int max();
    int min();
    void reverse();
    void reverse2();
    int linearSearch(int);
    int binarySearch(int);
    int recursiveBinarySearch(int, int, int);
};

Array::Array()
{
    size = 10;
    length = 0;
    A = new int[size];
}

Array::~Array()
{
    delete[] A;
}

void Array::swap(int a, int b)
{
    int temp = A[b];
    A[b] = A[a];
    A[a] = temp;
}

void Array::display()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
}

void Array::append(int x)
{
    if (length < size)
        A[length++] = x;
}

void Array::insert(int index, int x)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    }
}

void Array::remove(int index)
{
    if (index >= 0 && index < length)
    {
        for (int i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
    }
}

int Array::get(int index)
{
    if (index >= 0 && index < length)
        return A[index];
    return -1;
}

void Array::set(int index, int x)
{
    if (index >= 0 && index < length)
        A[index] = x;
}

int Array::sum()
{
    int total = 0;
    for (int i = 0; i < length; i++)
        total = total + A[i];
    return total;
}

int Array::sumRecursive(int n)
{
    if (n < 0)
        return 0;
    return sumRecursive(n - 1) + A[n];
}

int Array::max()
{
    int max = A[0];
    for (int i = 0; i < length; i++)
    {
        if (max < A[i])
            max = A[i];
    }
    return max;
}

int Array::min()
{
    int min = A[0];
    for (int i = 0; i < length; i++)
    {
        if (min > A[i])
            min = A[i];
    }
    return min;
}

int Array::linearSearch(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (A[i] == key)
            return i;
    }
    return -1;
}

int Array::binarySearch(int key)
{
    int l = 0, h = length - 1, mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

void Array::reverse()
{
    int B[length];
    for (int i = length - 1, j = 0; i >= 0; i--, j++)
        B[j] = A[i];

    for (int i = 0; i < length; i++)
        A[i] = B[i];
}

void Array::reverse2()
{
    for (int i = 0, j = length - 1; i < j; i++, j--)
        swap(i, j);
}

int Array::recursiveBinarySearch(int l, int h, int key)
{
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            return recursiveBinarySearch(l, mid - 1, key);
        else
            return recursiveBinarySearch(mid + 1, h, key);
    }
    return -1;
}

int main()
{
    Array arr;
    int choice, element, index;
    do
    {
        cout << endl;
        cout << "1. Display" << endl;
        cout << "2. Append" << endl;
        cout << "3. Insert" << endl;
        cout << "4. Remove" << endl;
        cout << "5. Linear Search" << endl;
        cout << "6. Binary Search" << endl;
        cout << "7. Get" << endl;
        cout << "8. Set" << endl;
        cout << "9. Sum" << endl;
        cout << "10. Find Max and Min" << endl;
        cout << "11. Reverse" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            arr.display();
            break;
        case 2:
            cout << "Enter the element: ";
            cin >> element;
            arr.append(element);
            break;
        case 3:
            cout << "Enter index and element: ";
            cin >> index >> element;
            arr.insert(index, element);
            break;
        case 4:
            cout << "Enter the index of element: ";
            cin >> index;
            arr.remove(index);
            break;
        case 5:
            cout << "Enter the element: ";
            cin >> element;
            cout << arr.linearSearch(element);
            break;
        case 6:
            cout << "Enter the element: ";
            cin >> element;
            cout << arr.binarySearch(element);
            break;
        case 7:
            cout << "Enter the index: ";
            cin >> index;
            cout << arr.get(index);
            break;
        case 8:
            cout << "Enter the index and element: ";
            cin >> index >> element;
            arr.set(index, element);
            break;
        case 9:
            cout << arr.sum();
            break;
        case 10:
            cout << "Minimum: " << arr.min() << endl
                 << "Maximum: " << arr.max();
            break;
        case 11:
            arr.reverse();
            arr.display();
        }
    } while (choice < 12);
    return 0;
}
