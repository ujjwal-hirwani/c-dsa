// USP
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

class Stack
{
    deque<int> dq;

    public:
    // can be done either by front end or back end.
    void push(int val)
    {
        dq.push_front(val);
    }

    void pop()
    {
        dq.pop_front();
    }

    int top()
    {
        return dq.front();
    }

    bool empty()
    {
        return dq.empty();
    }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    
    while (!s.empty())
    {
        cout << s.top() << "\t";
        s.pop();
    }
    cout << endl;
    return 0;
}