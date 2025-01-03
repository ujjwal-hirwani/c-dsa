// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int fac(int n)
{
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}
int grid_ways(int n, int m)
{
    return fac(m + n - 2)/(fac(m - 1) * fac(n - 1)); // Power of Mathematics.
    // nPr
    //          n!
    // ways = --------
    //          x! y!
    // here x and y are repeated elements.
}
int main()
{
    cout << grid_ways(3, 3) << endl;
    return 0;
}