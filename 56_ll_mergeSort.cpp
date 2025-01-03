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
    Node *mergeSort(Node *head);
    Node *splitAtMid(Node *head);
    Node *merge(Node *left, Node *right);
    friend int main();
};
int main()
{
    List ll;
    ll.push_back(5);
    ll.push_back(4);
    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(1);
    ll.printList();
    ll.head = ll.mergeSort(ll.head);
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
Node *List ::mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *rightHead = splitAtMid(head);
    Node *left = mergeSort(head);
    Node *right = mergeSort(rightHead);
    return merge(left, right);
}
Node *List ::splitAtMid(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    return slow;
}
Node *List ::merge(Node *left, Node *right)
{
    List sorted;
    Node *i = left;
    Node *j = right;
    while (i != NULL && j != NULL)
    {
        if (i->data < j->data)
        {
            sorted.push_back(i->data);
            i = i -> next;
        }
        else
        {
            sorted.push_back(j->data);
            j = j -> next;
        }
    }
    while (i != NULL)
    {
        sorted.push_back(i->data);
        i = i->next;
    }
    while (j != NULL)
    {
        sorted.push_back(j->data);
        j = j->next;
    }
    return sorted.head;
}