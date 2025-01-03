// USP
#include <iostream>
#include <list>
#include <iterator>
using namespace std;
template <class T>
class Node
{
public:
	T data;
	Node *next;
	Node()
	{
		next = NULL;
	}
};
template <class T>
class Stack
{
public:
	Node<T> *head = NULL;
	void push(T val)
	{
		// push front
		Node<T> *newnode = new Node<T>;
		newnode->data = val;
		if (head == NULL)
			head = newnode;
		else
		{
			newnode->next = head;
			head = newnode;
		}
	}
	void pop()
	{
		// pop front
		if (head == NULL)
			return;
		else if (head->next == NULL)
		{
			delete head;
			head = NULL;
		}
		else
		{
			Node<T> *temp = head;
			head = head->next;
			delete temp;
		}
	}
	T top()
	{
		return head->data;
	}
	bool isEmpty()
	{
		return head == NULL;
	}
	void print()
	{
		Node<T> *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
};
int main()
{
	Stack<int> s;
	s.push(3);
	s.push(2);
	s.push(1);
	s.print();
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	s.print();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.print();
	return 0;
}