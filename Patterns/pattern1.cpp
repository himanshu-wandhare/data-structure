#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value: ";
    cin >> n;

    // for numbers
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << j << " ";
        cout << endl;
    }

    cout << endl;
    // for characters
    for (int i = 0; i < n; i++)
    {
        char ch = 'A';

        for (int j = 0; j < n; j++)
        {
            cout << ch << " ";
            ch = ch + 1;
        }
        cout << endl;
    }
    return 0;
}