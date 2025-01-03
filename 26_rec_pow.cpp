// USP
# include <iostream>
using namespace std;
int pow (int x, int n);
int pow_logn(int x, int n);
int main()
{
    cout << pow_logn (3, 4) << endl;
    return 0;
}
int pow (int x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    else
        return x * pow(x, n - 1);
}
int pow_logn(int x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n%2 == 0)
        return pow_logn(x, n/2) * pow_logn(x, n/2);
    else
        return x * pow_logn(x, n/2) * pow_logn(x, n/2);
}