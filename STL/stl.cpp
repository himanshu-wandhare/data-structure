#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers = {2, 4, 5, 6, 7, 9};

    pair<int, char> p1 = {1, 'A'};

    cout << p1.first << p1.second;

    auto printNums = []()
    {
        for (int i = 0; i < 10; i++)
            cout << i << " ";
    };

    printNums();

    cout << "Size" << numbers.size() << endl;
    numbers.push_back(30);

    for (auto it = numbers.begin(); it != numbers.end(); it++)
        cout << *it;
}