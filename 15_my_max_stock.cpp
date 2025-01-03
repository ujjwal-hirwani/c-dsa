#include <iostream>
using namespace std;
void max_stock_profit(int stock[], int size)
{
    int max_profit = 0;
    // assuming every day as a buying day so we find a best selling day for each day
    // 7, 1, 5, 3, 6, 4     buying day
    // 6, 6, 6, 6, 4, -inf   selling day
    //-1, 5, 1, 3,-2, -inf
    int sell[100000];
    sell[size - 1] = INT16_MIN;
    for (int i = size - 2; i >= 0; i--)
    {
        sell[i] = max(stock[i + 1], sell[i + 1]);
    }
    for (int i = 0; i < size; i++)
    {
        cout<<sell[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < size; i++)
    {
        max_profit = max(max_profit, sell[i] - stock[i]);
    }
    cout << max_profit << endl;
}
int main()
{
    int a[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(a) / sizeof(int);
    max_stock_profit(a, n);
    return 0;
}