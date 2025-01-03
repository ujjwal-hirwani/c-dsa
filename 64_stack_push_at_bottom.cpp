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
void pushAtBottomItr(stack<T>& s, T val)
{
	stack<T> temp;
	while (!s.empty())
	{
		temp.push(s.top());
		s.pop();
	}
	s.push(val);
	while(!temp.empty())
	{
		s.push(temp.top());
		temp.pop();
	}
}
int main()
{
	stack<int> s;
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	pushAtBottomItr<int>(s, 0);
	pushAtBottomRec<int>(s, -1);
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}