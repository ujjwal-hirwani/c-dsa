// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void combinations(string str, string ans);
int main()
{
    string str = "27";
    combinations(str, "");
    return 0;
}
void combinations(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    string letters[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int index = (int)str[0] - 50;
    for (int i = 0; i < letters[index].length(); i++)
    {
        combinations(str.substr(1, str.length() - 1), ans + letters[index][i]);
    }
}