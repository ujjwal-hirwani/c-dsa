// USP
// This is a O(n) solution.
#include <iostream>
#include <vector>
using namespace std;
void remove_duplicate(string str, string &dis, int ind, vector<bool> &map);
int main()
{
    string s = "aappnnacollege";
    string dis = "";
    vector<bool> map(26, false);
    remove_duplicate(s, dis, 0, map);
    cout << dis << endl;
    return 0;
}
void remove_duplicate(string str, string &dis, int ind, vector<bool> &map)
{
    if (ind == str.length())
        return;
    if (!map[(int)(str[ind] - 'a')])
    {
        map[(int)(str[ind] - 'a')] = true;
        dis = dis + str[ind];
    }
    remove_duplicate(str, dis, ind + 1, map);
}