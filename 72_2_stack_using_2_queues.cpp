// USP
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// Approach 1:
// push() O(1)
// pop() O(n)
// front() O(n)

class Stack
{
    queue<int> q1;
    queue<int> q2;

    public:
    void push(int val)
    {
        q1.push(val);
    }
    void pop()
    {
        if (empty())
            return;
        while(q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    int top()
    {
        if (empty())
            return -1;
        while(q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(q1.front()); // This is were you made error.
        q1.pop();
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
    }
    bool empty()
    {
        return q1.empty();
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
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}