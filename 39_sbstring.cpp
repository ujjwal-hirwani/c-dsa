// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_substring(string str, string subs);
int main()
{
    print_substring("abc", "");   
    return 0;
}
void print_substring(string str, string subs)
{
    if (str.size() == 0)
    {
        cout << subs << endl;
        return;
    }
    print_substring(str.substr(1, str.size() - 1), subs + str[0]);
    print_substring(str.substr(1, str.size() - 1), subs);
}