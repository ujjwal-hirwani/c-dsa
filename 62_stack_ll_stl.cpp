// USP
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

template <class T>
class Stack
{
    list<T> ll;

public:
    void push(T val)
    {
        ll.push_front(val);
    }
    void pop()
    {
        if (!isEmpty())
            ll.pop_front();
    }
    T top()
    {
        return ll.front();
    }
    bool isEmpty()
    {
        return ll.size() == 0;
    }
};
int main()
{
    Stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    for (int i = 0; i < 3; i++)
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}