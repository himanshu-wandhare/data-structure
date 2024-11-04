#include <iostream>
using namespace std;

struct Matrix
{
    int A[10];
    int n;
};

int set(Matrix *m, int i, int j, int x)
{
    if(i == j)
        m->A[i-1] = x;
}

int get(Matrix *m, int i, int j)
{
    if(i == j)
        return m->A[i-1];
    else    
        return 0;
}

void Display(Matrix m)
{
    for(int i = 0; i < m.n; i++)
    {
        for(int j = 0; j < m.n; j++)
        {
            if(i == j)
                cout << m.A[i] << " ";
            else    
                cout << 0 <<" ";
        }
        cout<<endl;
    }
}

int main()
{
    Matrix M;
    M.n = 5;
    set(&M, 1,1,3);
    set(&M, 2,2,6);
    set(&M, 3,3,7);
    set(&M, 4,4,5);
    set(&M, 5,5,6);
    Display(M);
    return 0;
}