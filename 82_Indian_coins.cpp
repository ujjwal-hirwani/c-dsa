// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minCoins(vector<int> coins, int amount)
{
    int count = 0;
    for (int i = coins.size() - 1; i >= 0; i--)
    {
        if (coins[i] <= amount)
        {
            count += amount / coins[i];
            amount = amount % coins[i];
        }
    }
    return count;
}
int main()
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int amount = 1099;
    cout << minCoins(coins, amount) << endl;
    return 0;
}