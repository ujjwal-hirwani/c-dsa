// USP
// This is a good implementation of recursive nested functions. But this a O(n^2) solution.
#include <iostream>
using namespace std;
bool find_char(string str, char c, int ind);
void remove_duplicate(string str, string &check, int ind);
int main()
{
    string s = "Ujjwal Hirwani";
    string check = "";
    remove_duplicate(s, check, 0);
    cout << check << endl;
    return 0;
}
bool find_char(string str, char c, int ind)
{
    if (ind == str.length())
        return false;
    if (str[ind] == c)
        return true;
    return find_char(str, c, ind + 1);
}
void remove_duplicate(string str, string &check, int ind)
{
    if (ind == str.length())
        return;
    if (!(find_char(check, str[ind], 0)))
        check += str[ind];
    remove_duplicate(str, check, ind + 1);
}