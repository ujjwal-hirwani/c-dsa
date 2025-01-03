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
    void push_back(int val);
    void printList();
    void pop_back();
    void swap(int key1, int key2);
};
int main()
{
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);
    ll.push_back(9);
    ll.push_back(10);
    ll.push_back(11);
    ll.push_back(12);
    ll.printList();
    ll.swap(8, 4);
    ll.printList();
    return 0;
}

void List ::push_back(int val)
{
    size++;
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
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

void List ::pop_back()
{
    if (head == NULL)
        cout << "list is empty !!!" << endl;
    else
    {
        size--;
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
}
void List ::swap(int key1, int key2)
{
    // locating keys and their previous nodes.
    Node *k1 = head;
    Node *k2 = head;
    Node *p1;
    Node *p2;
    while (k1->data != key1 && k1 != NULL)
    {
        p1 = k1;
        k1 = k1->next;
    }
    while (k2->data != key2 && k2 != NULL)
    {
        p2 = k2;
        k2 = k2->next;
    }
    if (k1 == head)
    {
        p2->next = k1;
        k2->next = k1->next;
        k1->next = NULL;
        head = k2;
        return;
    }
    if (k2 == head)
    {
        p1->next = k2;
        k1->next = k2->next;
        k2->next = NULL;
        head = k1;
        return;
    }
    p1->next = k2;
    p2->next = k1;
    Node *temp = k1->next;
    k1->next = k2->next;
    k2->next = temp;
}