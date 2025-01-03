// USP
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_front(2);
    dq.push_front(1);
    dq.push_back(3);
    dq.push_back(4);

    cout << dq.front() << endl;
    cout << dq.back() << endl;

    while (!dq.empty())
    {
        cout << dq.front() << "\t";
        dq.pop_front(); 
    }
    cout << endl;
    return 0;
}