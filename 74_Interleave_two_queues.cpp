// USP
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
void interleaveTwoQueues(queue<int>& q)
{
    int n = q.size();
    queue<int> temp;
    for (int i = 0; i < n / 2; i++)
    {
        temp.push(q.front());
        q.pop();
    }
    while (!temp.empty())
    {
        q.push(temp.front());
        temp.pop();
        q.push(q.front());
        q.pop();
    }
    // if (n % 2 == 1)
    //     q.push(q.front());      //uncomment this line if you want to make sure 
    //                             //the first element of the first queue remains first.
    //     q.pop();
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    interleaveTwoQueues(q);
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}