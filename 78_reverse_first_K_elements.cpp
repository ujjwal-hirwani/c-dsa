// USP
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
void reverseK(queue<int> &q, int k)
{
    stack<int> s;
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < q.size() - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8}, k = 6;
    queue<int> q;
    for (int i = 0; i < 8; i++)
    {
        q.push(a[i]);
    }
    reverseK(q, k);
    while (!q.empty())
    {
        cout << q.front() << "\t";
        q.pop();
    }
    cout << endl;
    return 0;
}