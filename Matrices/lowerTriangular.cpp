#include <iostream>
using namespace std;

struct Matrix
{
    int *A;
    int n;
};

// using column major formula
int set(Matrix *m, int i, int j, int x)
{
    if (i >= j)
        m->A[(m->n * (j - 1) - (j - 2) * (j - 1) / 2) + (i - j)] = x;
}

int get(Matrix *m, int i, int j)
{
    if (i >= j)
        return m->A[(m->n * (j - 1) - (j - 2) * (j - 1) / 2) + (i - j)];
    else
        return 0;
}

// using row major formula
int set(Matrix *m, int i, int j, int x)
{
    if (i >= j)
        m->A[i * (i - 1) / 2 + j - 1] = x;
}

int get(Matrix *m, int i, int j)
{
    if (i >= j)
        return m->A[i * (i - 1) / 2 + j - 1];
    else
        return 0;
}

void Display(Matrix m)
{
    for (int i = 1; i < m.n; i++)
    {
        for (int j = 1; j < m.n; j++)
        {
            cout << get(&m, i, j) << " ";
        }
        cout << endl;
    }
}

int main()
{
    Matrix M;
    M.n = 5;
    M.A = new int[(M.n * (M.n + 1)) / 2];
    set(&M, 1, 1, 3);
    set(&M, 2, 1, 6);
    set(&M, 2, 2, 6);
    set(&M, 3, 1, 7);
    set(&M, 3, 2, 7);
    set(&M, 3, 3, 7);
    set(&M, 4, 1, 5);
    set(&M, 4, 2, 5);
    set(&M, 4, 3, 5);
    set(&M, 4, 4, 5);
    set(&M, 5, 1, 6);
    set(&M, 5, 2, 6);
    set(&M, 5, 3, 6);
    set(&M, 5, 4, 6);
    set(&M, 5, 5, 6);
    Display(M);
    return 0;
}