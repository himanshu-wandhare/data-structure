#include <iostream>
using namespace std;

struct Matrix
{
    int *A;
    int n;
};

// using column major formula
// int set(Matrix *m, int i, int j, int x)
// {
//     if (i <= j)
//         m->A[(m->n * (i - 1) - (i - 2) * (i - 1) / 2) + (j - i)] = x;
// }

// int get(Matrix *m, int i, int j)
// {
//     if (i <= j)
//         return m->A[(m->n * (i - 1) - (i - 2) * (i - 1) / 2) + (j - i)];
//     else
//         return 0;
// }

// using row major formula
int set(Matrix *m, int i, int j, int x)
{
    if (i <= j)
        m->A[j * (j - 1) / 2 + i - 1] = x;
}

int get(Matrix *m, int i, int j)
{
    if (i <= j)
        return m->A[j * (j - 1) / 2 + i - 1];
    else
        return 0;
}

void Display(Matrix m)
{
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            cout << get(&m, i, j) << " ";
        }
        cout << endl;
    }
}

int main()
{
    Matrix M;
    cout << "Enter the dimension of Matrix: ";
    cin >> M.n;

    M.A = new int[(M.n * (M.n + 1)) / 2];

    cout << "\nEnter elements in the matrix\n";
    for (int i = 1; i <= M.n; i++)
    {
        for (int j = 1; j <= M.n; j++)
        {
            int x;
            cin >> x;
            set(&M, i, j, x);
        }
    }
    Display(M);
    return 0;
}