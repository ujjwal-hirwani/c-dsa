// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_permutations(string str, string ans);
int main()
{
    // permutation of a string.
    print_permutations("abc", "");
    return 0;
}
void print_permutations(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < str.length(); i++)
    {
        string new_str = str.substr(0, i) + str.substr(i + 1, str.length() - i);
        print_permutations(new_str, ans + str[i]);
    }
}