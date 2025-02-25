// USP
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct comparePairs
{
    bool operator() (pair<string, int> p1, pair<string, int> p2)
    {
        return p1.second < p2.second;
    }
};

int main()
{
    priority_queue<pair<string, int>, vector<pair<string, int>>, comparePairs> pq;
    pq.push(make_pair("Ujjwal", 500));
    pq.push(make_pair("Nitin", 1000));
    pq.push(make_pair("Aradhya", 600));

    while (!pq.empty())
    {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}