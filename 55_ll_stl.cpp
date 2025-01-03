// USP
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

int main()
{
    list<int> ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    list<int> :: iterator itr;
    itr = ll.begin();
    advance(itr, 3);
    ll.insert(itr, 2, 99);
    for (itr = ll.begin(); itr != ll.end(); itr++)
    {
        cout << *(itr) << endl;
    }
    return 0;
}