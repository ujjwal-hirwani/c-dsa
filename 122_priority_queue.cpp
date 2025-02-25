// USP
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> pq;
    pq.push(5);
    pq.push(10);
    pq.push(2);
    pq.push(5);
    pq.push(8);
    pq.push(3);
    pq.push(9);
    pq.push(11);
    while (!pq.empty())
    {
        cout << pq.top() << "\t";
        pq.pop();
    }
    return 0;
}