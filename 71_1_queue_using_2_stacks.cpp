// USP
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Approach 1:
// push() O(n)
// pop() O(1)
// front() O(1)

class Queue
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int val) // O(n) push at bottom of a stack.
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop()
    {
        if (!s1.empty())
            s1.pop();
    }
    int front()
    {
        if (!s1.empty())
            return s1.top();
        return -1; // queue is empty.
    }
    bool empty()
    {
        return s1.empty();
    }
};
int main()
{
    Queue q;
    for (int i = 0; i < 5; i++)
    {
        q.push(i + 1);
    }
    while (!q.empty())
    {
        cout << q.front() << "\t";
        q.pop();
    }
    cout << endl;
    return 0;
}