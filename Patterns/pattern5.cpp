#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // for numbers
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;

    // for characters
    for (int i = 0; i < n; i++)
    {
        char ch = 'A';
        for (int j = 0; j <= i; j++)
        {
            cout << (char)(ch + j) << " ";
        }
        cout << endl;
    }
    return 0;
}