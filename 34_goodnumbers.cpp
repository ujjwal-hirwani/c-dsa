// USP
# include <iostream>
using namespace std;
long long MOD = 1e9 + 7;
long long fast_exp(long long x, long long n);
int countGoodNumbers(long long n);
int main()
{
    cout << countGoodNumbers(50) << endl;
    return 0;
}
long long fast_exp(long long base, long long exp)
{
    int res = 1;
    while (exp > 0)
    {
        if (exp & 1 != 0)
            res = (res * base) % MOD;
        exp = exp >> 1;
        base = (base * base) % MOD;
    }
    return res;
}
int countGoodNumbers(long long n)
{
    if (n % 2 == 0)
        return (fast_exp(5, n / 2) * fast_exp(4, n / 2)) % MOD;
    return (fast_exp(5, (n/2 + 1)) * fast_exp(4, n / 2)) % MOD;
}