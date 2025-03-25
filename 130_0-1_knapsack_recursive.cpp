// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int w, int n)
{
    if (w == 0 || n == 0)
        return 0;
    if (wt[n - 1] <= w)
    {
        // choice 1: include the object;
        // choice 2: do not include the object;
        return max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
    }
    return knapsack(wt, val, w, n - 1); // do not include the object;
}
int main()
{
    // input;
    vector<int> wt = {2, 1, 5, 3};
    vector<int> val = {300, 200, 400, 500};
    int w = 10;
    int n = wt.size();
    cout << knapsack(wt, val, w, n) << endl;
    return 0;
}