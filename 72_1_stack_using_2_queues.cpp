// USP
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// Approach 1:
// push() O(n)
// pop() O(1)
// front() O(1)

class Stack
{
    queue<int> q1;
    queue<int> q2;

public:
    // push() O(n)

    void push(int val)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(val);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop() // O(1)
    {
        if (q1.empty())
            return;
        q1.pop();
    }

    int top() // O(1)
    {
        if (q1.empty())
            return -1;
        return q1.front();
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
    s.push(6);

    while (!s.empty())
    {
        cout << s.top() << "\t";
        s.pop();
    }
    cout << endl;
    return 0;
}