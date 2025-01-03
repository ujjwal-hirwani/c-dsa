// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_subs(string str, string ans);
int main()
{
    // Program to print all possible substrings of a string.
    print_subs("abc", "");
    return 0;
}
void print_subs(string str, string ans)
{
    if (str.size() == 0)
    {
        cout << ans << endl;
        return;
    }
    print_subs(str.substr(0, str.size() - 1), ans + str[str.size() - 1]);
    print_subs(str.substr(0, str.size() - 1), ans);
}