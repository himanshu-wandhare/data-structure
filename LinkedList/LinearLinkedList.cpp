#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node *next;

    Node() : next(NULL) {}
    Node(int data) : val(data), next(NULL) {}
    Node(int data, Node *link) : val(data), next(link) {}
};

class LinkedList
{
public:
    Node *head = NULL;
    void create(vector<int>);
    void display();
    void rDisplay(Node *);
    int size();
    int rSize(Node *);
    int sum();
    int rSum(Node *);
    int getMax();
    int getRMax(Node *);
    Node *search(int);
    Node *rSearch(Node *, int);
    void insertFirst(int);
    void append(int);
    void insert(int);
    void insert(int, int);
    void deleteFirst();
    void deleteLast();
    void remove(int);
    bool isSorted();
    void removeDuplicates();
    void reverseElement();
    void reverse();
    void rReverse(Node *, Node *);
    void concat(Node *);
    void merge(Node *);
    static bool hasLoop(Node *);
};

void LinkedList::create(vector<int> nums)
{
    int length = nums.size();
    if (length == 0)
        return;

    head = new Node(nums[0]);
    Node *ptr = head;

    for (int i = 1; i < length; i++)
    {
        ptr->next = new Node(nums[i]);
        ptr = ptr->next;
    }
}
void LinkedList::display()
{
    Node *ptr = head;
    while (ptr)
    {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << "NULL";
}
void LinkedList::rDisplay(Node *ptr)
{
    if (!ptr)
    {
        cout << "NULL";
        return;
    }
    cout << ptr->val << "->";
    rDisplay(ptr->next);
}
int LinkedList::size()
{
    Node *ptr = head;
    int count = 0;
    while (ptr)
    {
        count++;
        ptr = ptr->next;
    }

    return count;
}
int LinkedList::rSize(Node *ptr)
{
    if (!ptr)
        return 0;
    return 1 + rSize(ptr->next);
}
int LinkedList::sum()
{
    int sum = 0;

    Node *ptr = head;
    while (ptr)
    {
        sum += ptr->val;
        ptr = ptr->next;
    }

    return sum;
}
int LinkedList::rSum(Node *ptr)
{
    if (!ptr)
        return 0;
    return ptr->val + rSum(ptr->next);
}
int LinkedList::getMax()
{
    if (!head)
        return -1;

    int largest = INT32_MIN;
    Node *ptr = head;
    while (ptr)
    {
        largest = max(largest, ptr->val);
        ptr = ptr->next;
    }
    return largest;
}
int LinkedList::getRMax(Node *ptr)
{
    if (!ptr)
        return INT32_MIN;

    int x = 0;
    x = getRMax(ptr->next);
    if (x > ptr->val)
        return x;
    return ptr->val;
}
Node *LinkedList::search(int value)
{
    Node *ptr = head;
    while (ptr && ptr->val != value)
    {
        ptr = ptr->next;
    }

    return ptr;
}
Node *LinkedList::rSearch(Node *ptr, int value)
{
    if (!ptr)
        return NULL;
    if (ptr->val == value)
        return ptr;
    return rSearch(ptr->next, value);
}
void LinkedList::insertFirst(int value)
{
    head = new Node(value, head);
}
void LinkedList::append(int value)
{
    Node *node = new Node(value);
    if (!head)
    {
        head = node;
        return;
    }
    Node *ptr = head;
    while (ptr->next)
        ptr = ptr->next;

    ptr->next = node;
}
void LinkedList::insert(int pos, int value)
{
    if (pos == 0)
        insertFirst(value);
    else if (pos == size())
        append(value);
    else
    {
        Node *ptr = head;
        for (int i = 0; i < pos - 1; i++)
        {
            ptr = ptr->next;
        }
        ptr->next = new Node(value, ptr->next);
    }
}
void LinkedList::insert(int value)
{
    if (!isSorted())
    {
        cout << "Linked List is not sorted";
        return;
    }

    Node *ptr = head;
    Node *prevNode = NULL;
    while (ptr && value > ptr->val)
    {
        prevNode = ptr;
        ptr = ptr->next;
    }
    if (!prevNode)
    {
        head = new Node(value, ptr);
    }
    else
    {
        prevNode->next = new Node(value, ptr);
    }
}
void LinkedList::deleteFirst()
{
    if (!head)
        return;

    Node *newHead = head->next;
    delete head;
    head = newHead;
}
void LinkedList::deleteLast()
{
    if (!head)
        return;

    Node *ptr = head;
    Node *prevNode = NULL;
    while (ptr->next)
    {
        prevNode = ptr;
        ptr = ptr->next;
    }
    prevNode->next = NULL;
    delete ptr;
}
void LinkedList::remove(int pos)
{
    if (pos == 0)
    {
        deleteFirst();
        return;
    }

    Node *ptr = head;
    for (int i = 0; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }
    Node *nodeToBeDeleted = ptr->next;
    ptr->next = ptr->next->next;
    delete nodeToBeDeleted;
}
bool LinkedList::isSorted()
{
    if (!head->next)
        return true;

    Node *ptr = head->next;
    int x = head->val;
    while (ptr && ptr->val > x)
    {
        x = ptr->val;
        ptr = ptr->next;
    }

    return !ptr ? true : false;
}
void LinkedList::removeDuplicates()
{
    if (!head->next)
        return;

    Node *ptr = head->next;
    Node *prevNode = head;
    while (ptr)
    {
        if (prevNode->val == ptr->val)
        {
            prevNode->next = ptr->next;
            delete ptr;
            ptr = prevNode->next;
        }
        else
        {
            prevNode = ptr;
            ptr = ptr->next;
        }
    }
}
void LinkedList::reverseElement()
{
    vector<int> v(size());

    Node *ptr = head;
    while (ptr)
    {
        v.push_back(ptr->val);
        ptr = ptr->next;
    }
    ptr = head;
    int i = v.size() - 1;
    while (ptr)
    {
        ptr->val = v[i--];
        ptr = ptr->next;
    }
}
void LinkedList::reverse()
{
    Node *p, *q, *r;
    p = q = NULL;
    r = head;

    while (r)
    {
        p = q;
        q = r;
        r = r->next;
        q->next = p;
    }
    head = q;
}
void LinkedList::rReverse(Node *q, Node *p)
{
    if (!p)
    {
        head = q;
        return;
    }
    rReverse(p, p->next);
    p->next = q;
}
void LinkedList::concat(Node *list)
{
    Node *ptr = head;
    while (ptr->next)
        ptr = ptr->next;

    ptr->next = list;
}
void LinkedList::merge(Node *head)
{
    Node *last, *mergedList;
    if (this->head->val < head->val)
    {
        mergedList = last = this->head;
        this->head = this->head->next;
        last->next = NULL;
    }
    else
    {
        mergedList = last = head;
        head = head->next;
    }
    last->next = NULL;

    while (this->head && head)
    {
        if (this->head->val < head->val)
        {
            last->next = this->head;
            last = this->head;
            this->head = this->head->next;
        }
        else
        {
            last->next = head;
            last = head;
            head = head->next;
        }
        last->next = NULL;
    }
    last->next = (head) ? head : this->head;
    this->head = mergedList;
}
bool LinkedList::hasLoop(Node *first)
{
    if (!first || !first->next)
        return false;

    Node *slow, *fast;
    slow = fast = first;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main()
{
    Node *node1 = new Node(40);
    Node *node = new Node(20, new Node(30, new Node(40, new Node(50, node1))));
    node1->next = node;
    cout << LinkedList::hasLoop(node);
}