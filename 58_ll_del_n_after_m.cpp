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
    void del_N_after_M(int m, int n);
    friend int main();
};
int main()
{
    List ll;
    int a[] = {9, 1, 3, 5, 9, 4, 10, 1};
    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        ll.push_back(a[i]);
    }
    ll.printList();
    ll.del_N_after_M(2, 1);
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
void List ::del_N_after_M(int m, int n)
{
    if (m == 0)
    {
        while (head != NULL)
        {
            Node *next = head->next;
            delete head;
            head = next;
        }
    }
    Node *curr = head;
    while (curr != NULL)
    {
        for (int i = 0; i < m - 1; i++)
        {
            if (curr == NULL)
                return;
            curr = curr->next;
        }
        for (int i = 0; i < n; i++)
        {
            if (curr == NULL || curr->next == NULL)
                return;
            Node *del = curr->next;
            curr->next = curr->next->next;
            delete del;
        }
        curr = curr->next;
    }
}