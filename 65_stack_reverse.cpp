// USP
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
template <class T>
void pushAtBottom(stack<T>& s, T val)
{
	//recursive approach
	if (s.empty())
	{
		s.push(val);
		return;
	}
	T temp = s.top();
	s.pop();
	pushAtBottom(s, val);
	s.push(temp);
}
int main()
{
	stack<int> s;
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}