// USP
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

template <class T>
void pushAtBottomRec(stack<T>& s, T val)
{
	//recursive approach
	if (s.empty())
	{
		s.push(val);
		return;
	}
	T temp = s.top();
	s.pop();
	pushAtBottomRec(s, val);
	s.push(temp);
}

template <class T>
void reverse(stack<T>& s)
{
	if (s.empty())
		return;
	T temp = s.top();
	s.pop();
	reverse(s);
	pushAtBottomRec(s, temp);
}
int main()
{
	stack<int> s;
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	reverse(s);
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}