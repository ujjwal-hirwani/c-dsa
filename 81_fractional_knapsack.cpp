// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<double, int> p1, pair<double, int> p2)
{
    return p1.first > p2.first;
}
int fractionalKnapsack(vector<int> val, vector<int> wt, int W)
{
    int n = val.size();
    vector<pair<double, int>> ratios(n, make_pair(0.0, 0));
    int ans = 0;
    for (int i = 0; i < n; i++) // strore ratios and index.
    {
        ratios[i] = make_pair((double)val[i] / (double)wt[i], i);
    }
    sort(ratios.begin(), ratios.end(), compare); // sort in descending order of ratios.
    for (int i = 0; i < n; i++)
    {
        int idx = ratios[i].second;
        if (wt[idx] <= W)
        {
            W -= wt[idx];
            ans += val[idx];
        }
        else
        {
            ans += ratios[i].first * W;
            W = 0;
            break; // sack is full!!!
        }
    }
    return ans;
}
int main()
{
    vector <int> value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int W = 50;
    cout << fractionalKnapsack(value, weight, W) << endl;
    return 0;
}