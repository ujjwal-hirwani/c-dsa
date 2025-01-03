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
	Node()
	{
		next = NULL;
	}
	friend class Queue;
};
class Queue
{
	Node *head, *tail;

public:
	Queue()
	{
		head = NULL;
		tail = NULL;
	}

	void push(int val)
	{
		Node *newNode = (Node *)new Node;
		newNode->data = val;
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
			return;
		}
		tail->next = newNode;
		tail = newNode;
	}
	void pop()
	{
		if (head == NULL)
			return;
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	int front()
	{
		if (head == NULL)
			return -1;
		return head->data;
	}

	bool isEmpty()
	{
		return head == NULL;
	}

	void print()
	{
		Node *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "\t";
			temp = temp->next;
		}
		cout << endl;
	}
};
int main()
{
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	while(q.isEmpty()== false)
	{
		cout << q.front() << endl;
		q.pop();
	}
	return 0;
}