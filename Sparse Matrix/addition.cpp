#include <iostream>
#include <stdexcept>
using namespace std;

struct Element
{
    int i;
    int j;
    int val;
};

struct Sparse
{
    int m;
    int n;
    int length;
    Element *elements;
};

void create(Sparse *s)
{
    cout << "Enter the dimension of matrix: ";
    cin >> s->m >> s->n;

    cout << "Enter the no. of non-zero elements: ";
    cin >> s->length;

    s->elements = new Element[s->length];

    cout << "Enter " << s->length << " elements" << endl;
    for (int i = 0; i < s->length; i++)
    {
        cin >> s->elements[i].i >> s->elements[i].j >> s->elements[i].val;
    }
}

void display(Sparse s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (s.elements[k].i == i && s.elements[k].j == j)
                cout << s.elements[k++].val << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

Sparse add(Sparse *a, Sparse *b)
{
    if (a->m != b->m || a->n != b->n)
        throw runtime_error("Dimension of matrices are not equal");

    Sparse result;
    result.elements = new Element[a->length + b->length];

    int i, j, k;
    i = j = k = 0;

    while (i < a->length && j < b->length)
    {
        if (a->elements[i].i < b->elements[j].i)
        {
            result.elements[k++] = a->elements[i++];
        }
        else if (a->elements[i].i > b->elements[j].i)
        {
            result.elements[k++] = b->elements[j++];
        }
        else
        {
            if (a->elements[i].j < b->elements[j].j)
                result.elements[k++] = a->elements[i++];
            else if (a->elements[i].j > b->elements[j].j)
                result.elements[k++] = b->elements[j++];
            else
            {
                result.elements[k] = a->elements[i];
                result.elements[k++].val = a->elements[i++].val + b->elements[j++].val;
            }
        }
    }
    while (i < a->length)
        result.elements[k++] = a->elements[i++];
    while (j < b->length)
        result.elements[k++] = b->elements[j++];
    result.m = a->m;
    result.n = b->n;
    result.length = k;

    return result;
}
int main()
{
    Sparse s1, s2, sum;
    create(&s1);
    create(&s2);

    cout << "Matrix 1\n";
    display(s1);

    cout << "Matrix 2\n";
    display(s2);

    sum = add(&s1, &s2);

    cout << "Sum of Matrix\n";
    display(sum);
}