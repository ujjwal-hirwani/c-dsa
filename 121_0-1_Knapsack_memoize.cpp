// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int KnapSack(vector<int> wt, vector<int> val, int w, int n, vector<vector<int>>& t)
{
    // Base Case
    {
        if (n == 0 || w == 0)
            return 0;
        if (t[w][n] != -1)
            return t[w][n];
        if (wt[n - 1] <= w)
            // choice 1: choose the object;
            // choice 2: do not choose the object;
            return t[w][n] = max(val[n - 1] + KnapSack(wt, val, w - wt[n - 1], n - 1, t), KnapSack(wt, val, w, n - 1, t));
        return t[w][n] = KnapSack(wt, val, w, n - 1, t);
    }
}
int main()
{
    vector<int> wt = {2, 1, 5, 3};
    vector<int> val = {300, 200, 400, 500};
    int w = 10, n = wt.size();
    vector<vector<int>> t(w + 1, vector<int> (n + 1, -1));
    cout << KnapSack(wt, val, w, wt.size(), t);
    return 0;
}