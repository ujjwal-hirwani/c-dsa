// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int fibonacci(int n, vector<int>& table)
{
    if (n == 0 || n == 1)
        return table[n] = n;
    else if (table[n] != -1)
        return table[n];
    return table[n] = fibonacci(n - 1, table) + fibonacci(n - 2, table);
}
int main()
{
    int n; 
    cout << "Enter any number: ";
    cin >> n;
    vector<int> table(n + 1, -1);
    cout << fibonacci(n, table) << endl;
    return 0;
}