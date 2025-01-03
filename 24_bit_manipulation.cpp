// USP
#include <iostream>
using namespace std;
void checkOddEven(int n);
int getIthBit(int n, int i);
int setIthBit(int n, int i);
int clearIthBit(int n, int i);
int updateIthBit(int n, int i, int val);
bool checkPowerTwo(int n);
int clearLastIBits(int n, int i);
int countSetBits(int n);
int fastExponenetation(int base, int pow);
int main()
{
    // cout << checkPowerTwo(5) << endl;
    // cout << updateIthBit(7, 3, 1) << endl;
    // cout << clearLastIBits(15, 2) << endl;
    // cout << countSetBits(293) << endl;
    cout << fastExponenetation(25, 2) << endl;
    return 0;
}
void checkOddEven(int n)
{
    // This is a bitwise implimentation.
    if (n & 1 == 1)
        cout << n << " is odd." << endl;
    else
        cout << n << " is even." << endl;
}
int getIthBit(int n, int i)
{
    int mask = 1 << i;
    // int temp = n & mask;
    // if (temp == 0)
    //     return 0;
    if (!(n & mask))
        return 0;
    else
        return 1;
}
int setIthBit(int n, int i)
{
    int mask = 1 << i;
    return (int)n | mask;
}
int clearIthBit(int n, int i)
{
    int mask = ~(1 << i);
    return (int)(n & mask);
}
bool checkPowerTwo(int n)
{
    if ((int)(n & (n - 1)) == 0)
        return true;
    else
        return false;
}
int updateIthBit(int n, int i, int val)
{
    // clear i th bit;
    n = n & ~(1 << i);
    // set i th bit with a value;
    n = n | (val << i);
    return n;
}
int clearLastIBits(int n, int i)
{
    return n & (~0 << i);
}
int countSetBits(int n)
{
    int count = 0;
    while (n != 0)
    {
        count += (n & 1);
        n = n >> 1;
    }
    return count;
}
int fastExponenetation(int base, int pow)
{
    int ans = 1;
    while (pow != 0)
    {
        if ((pow & 1) != 0)
        {
            ans *= (pow & 1) * base;
        }
        base *= base;
        pow = pow >> 1;
    }
    return ans;
}