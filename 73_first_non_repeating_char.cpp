// USP
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
string firstNonRepeatingChar(string s)
{
    string ans = "";
    vector<int> freq(26, 0);
    queue<char> q;
    for (int i = 0; i < s.size(); i++)
    {
        q.push(s[i]);
        freq[s[i] - 'a']++;
        while (!q.empty() && freq[q.front() - 'a'] > 1)
        {
            q.pop();
        }
        if (q.empty())
            ans += "-1";
        else
            ans += q.front();
    }
    return ans;
}
int main()
{
    string s = "aabccxb";
    cout << firstNonRepeatingChar(s) << endl;
    return 0;
}