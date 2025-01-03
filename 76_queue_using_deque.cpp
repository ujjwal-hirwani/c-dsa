// USP
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

class Queue
{
    deque<int> dq;

    public:

    void push(int val)
    {
        dq.push_back(val);
    }

    void pop()
    {
        dq.pop_front();
    }

    int front()
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
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    
    while (!q.empty())
    {
        cout << q.front() << "\t";
        q.pop();
    }
    cout << endl;
    return 0;
}