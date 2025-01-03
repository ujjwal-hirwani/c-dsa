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
    void push_back(int val);
    void printList();
    void insert(int val, int pos);
    void pop_front();
    void pop_back();
    int searchItr(int key);
    int searchRec(int key);
    int helper(int key, Node *head);
    void reverseList();
    void removeNth(int n); // from last
    ~List()
    {
        while (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        head = NULL;
    }
};
int main()
{
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.printList();
    ll.pop_front();
    ll.pop_back();
    ll.printList();
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
void List ::insert(int val, int pos)
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
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Invalid index !!!" << endl;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
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
int List ::searchItr(int key)
{
    Node *temp = head;
    int ind = 0;
    while (temp->next != NULL)
    {
        if (key == temp->data)
            return ind;
        ind++;
        temp = temp->next;
    }
    return -1; // Key not found.
}
int List ::searchRec(int key)
{
    return helper(key, head);
}
int List ::helper(int key, Node *head)
{
    if (head == NULL)
        return -1;
    if (head->data == key)
        return 0;
    if (helper(key, head->next) == -1)
        return -1;
    return helper(key, head->next) + 1;
}
void List ::reverseList()
{
    Node *prev = NULL;
    Node *temp = head;
    Node *nxt = NULL;
    while (temp != NULL)
    {
        nxt = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nxt;
    }
    tail = head;
    head = prev;
}
void List ::removeNth(int n)
{
    Node *temp = head;
    for (int i = 1; i < size - n; i++)
    {
        temp = temp->next;
    }
    Node *del = temp->next;
    temp->next = temp->next->next;
    delete del;
}