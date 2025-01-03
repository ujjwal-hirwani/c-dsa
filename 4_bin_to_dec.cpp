// USP
// binary to decimal.
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n = 100100101, exp = 0, dec = 0;
    while (n != 0)
    {
        dec += (n % 10) * pow(2, exp);
        n /= 10;
        exp++;
    }
    cout<<dec<<endl;
    return 0;
}