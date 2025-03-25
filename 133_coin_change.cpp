// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int> coins, int value)
{
    sort(coins.begin(), coins.end(), greater<int>());
    vector<int> coinUsed;
    for(int i = 0; i < coins.size(); i++)
    {
        while(value >= coins[i])
        {
            coinUsed.push_back(coins[i]);
            value -= coins[i];
        }
    }
    cout << "Coins Used: " << endl;
    for (int i = 0; i < coinUsed.size(); i++)
    {
        cout << coinUsed[i] << endl;
    }
    return coinUsed.size();
}
int main()
{
    vector<int> coins = {1, 2, 5, 10, 20};
    cout << "Number of Coins used: " << coinChange(coins, 55) << endl;
    return 0;
}