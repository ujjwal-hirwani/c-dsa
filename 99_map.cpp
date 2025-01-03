// USP
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    map<int, string> m;
    m[1] = "Ujjwal";
    m[2] = "Vishu";
    m[3] = "Varun";
    m[4] = "Vasudev";
    m[0] = "Shilpi";
    cout << m[4] << endl;

    m[4] = "Boss";
    cout << m[4] << endl;
    cout << m.count(5) << endl;
    cout << m.count(1) << endl;

    for (auto it : m) // always iterates in assending order of keys.
    {
        cout << "Roll number: " << it.first <<"\tName: " << it.second << endl;
    }
    return 0;
}