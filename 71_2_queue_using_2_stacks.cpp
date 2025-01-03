// USP
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
// Approach 1:
// push() O(1)
// pop() O(n)
// front() O(n)

class Queue
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int val)
    {
        s1.push(val);
    }
    void pop()
    {
        if (empty())
            return;
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int front()
    {
        if (empty())
            return -1; // queue is empty.
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    bool empty()
    {
        return s1.empty();
    }
    void print()
    {
        while(!s1.empty())
        {
            cout << s1.top() << endl;
            s1.pop();
        }
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
    while(!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}