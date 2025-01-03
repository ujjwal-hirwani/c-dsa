// USP
#include <iostream>
using namespace std;
int factorial(int n);
int binomial_coefficient(int n, int r);
int main()
{
    int n = 10, r = 2;
    cout << binomial_coefficient(n, r) << endl;
    return 0;
}
int factorial(int n)
{
    int fac = 1;
    for (int i = 1; i <= n; i++)
    {
        fac *= i;
    }
    return fac;
}
int binomial_coefficient(int n, int r)
{
    return factorial(n) / ((factorial(n - r) * factorial(r)));
}