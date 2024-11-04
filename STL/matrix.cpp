#include <iostream>
#include <vector>
using namespace std;

// 00 01 02
// 10 11 12
// 20 21 22
void rowSum(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < matrix[i].size(); j++)
            sum += matrix[i][j];
        cout << "Row " << i << ": " << sum << endl;
    }
}

void colSum(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < matrix[i].size(); j++)
            sum += matrix[j][i];
        cout << "Col " << i << ": " << sum << endl;
    }
}
void diagonal(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << matrix[i][(matrix.size() - 1) - i] << endl;
    }
}

int main()
{
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    rowSum(matrix);
    cout << endl;

    colSum(matrix);
    cout << endl;

    diagonal(matrix);
}