#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;

    Node(int x, Node *ref) : val(x), next(ref) {};
};

int getDecimalValue(Node *head)
{
    static int p = 1;
    if (head == NULL)
    {
        return 0;
    }
    int x = getDecimalValue(head->next) + head->val * p;
    p = p * 2;
    return x;
}

int main()
{
    Node *head = new Node(1, new Node(0, new Node(1, NULL)));
    cout << getDecimalValue(head);
}