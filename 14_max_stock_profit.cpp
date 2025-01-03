// USP
#include <iostream>
using namespace std;
int max_stock_profit(int stock[], int size)
{
    // assuming that each day is a selling day.
    // to calculate best buying day for each day.
    int buy[1000000];
    buy[0] = INT32_MAX;
    for (int i = 1; i < size; i++)
    {
        buy[i] = min(buy[i - 1], stock[i]);
    }
    int profit = 0;
    for (int i = 0; i < size; i++)
    {
        profit = max(profit, stock[i] - buy[i]);
    }
    return profit;
    // O(n^2) -> better.
}
int main()
{
    int a[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(a) / sizeof(int);
    cout << "Maximum profit: " << max_stock_profit(a, n) << endl;
    // int profit = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j <n; j++)
    //     {
    //         int diff = a[j] - a[i];
    //         profit = max(profit, diff);
    //     }
    // }
    // cout << profit << endl;
    // O(n^2) -> not good.
    return 0;
}