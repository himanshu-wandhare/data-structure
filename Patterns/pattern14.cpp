#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int j = 0; j < 2 * n - 1; j++)
    {
        for (int k = 0; k < 2 * n - 1; k++)
        {
            int top = j;
            int left = k;
            int right = (2 * n - 2) - k;
            int bottom = (2 * n - 2) - j;

            cout << n - min(min(top, bottom), min(left, right)) << " ";
        }
        cout << endl;
    }
    return 0;
}