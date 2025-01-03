// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void string_permutations(string str, string ans);
int main()
{
    string_permutations("abcdefghijklmnopqrstuvwxyz", "");
    return 0;
}
void string_permutations(string str, string ans)
{
    if (str.size() == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        string nxtstr = str.substr(0, i) + str.substr(i + 1, str.size() - i - 1);
        string_permutations(nxtstr, ans + ch);
    }
}