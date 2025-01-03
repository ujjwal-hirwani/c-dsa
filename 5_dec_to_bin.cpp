// USP
// decimal to binary.
#include <iostream>
using namespace std;

int main()
{
    int n = 29, result = 0, mul = 1;
    while (n != 0)
    {
        result = (n % 2) * mul + result;
        mul *= 10;
        n /= 2;
    }
    cout << result << endl;
    return 0;
}