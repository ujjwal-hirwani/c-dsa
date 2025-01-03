// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node(int val)
    {
        data = val;
        next = NULL;
    }
    friend class List;
    friend int main();
};
class List
{
    Node *head;
    Node *tail;
    int size;

public:
    List()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void push_front(int val);
    void printList();
    void pop_front();
    bool isCycle();
    friend int main();
};
int main()
{
    List ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.tail -> next = ll.head -> next;
    cout << boolalpha << ll.isCycle() << endl;
    return 0;
}

void List ::push_front(int val)
{
    Node *newNode = new Node(val);
    size++;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void List ::printList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void List ::pop_front()
{
    if (head == NULL)
        cout << "List is empty !!!" << endl;
    else
    {
        size--;
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
bool List ::isCycle()
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if (slow == fast)
            return true;
    }
    return false;
}