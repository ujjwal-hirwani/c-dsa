// USP
#include <iostream>
using namespace std;
int rec_fast_exp(int x, int n, int res);
int main()
{
    cout << rec_fast_exp(2, 10, 1) << endl;
    return 0;
}
int rec_fast_exp(int x, int n, int res)
{
    if (n == 0)
        return res;
    if (n & 1 != 0)
        return rec_fast_exp(x * x, n >> 1, res * x);
    return rec_fast_exp(x * x, n >> 1, res);
}