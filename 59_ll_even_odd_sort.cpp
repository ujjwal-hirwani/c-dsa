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
    void evenOddSort();
    friend int main();
};
int main()
{
    List ll;
    int a[] = {1, 3, 5, 7, 8};
    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        ll.push_back(a[i]);
    }
    ll.printList();
    ll.evenOddSort();
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
void List ::evenOddSort()
{
    Node *curr = head;
    Node *prev = NULL;
    Node *track = NULL;
    while (curr != NULL)
    {
        // prev = curr; // This was the error. Note whenever you face a bug use pen and paper !!!.
        if (curr->data % 2 == 0) // even
        {
            if (curr == head)
                track = head;

            else if (track == NULL)
            {
                prev->next = prev->next->next;
                curr->next = head;
                head = curr;
                track = curr;
                curr = prev;
            }
            else if (track->next == curr)
                track = curr;
            else
            {
                prev->next = prev->next->next;
                curr->next = track->next;
                track->next = curr;
                track = curr;
                curr = prev;
            }
        }
        prev = curr; // This was the error.
        curr = curr->next;
    }
}