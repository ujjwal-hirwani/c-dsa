// USP
# include <iostream>
using namespace std;
int tiling(int n);
int main()
{
    int n = 3;
    cout << tiling(4) << endl;
    return 0;
}
int tiling(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return tiling(n - 1) + tiling (n - 2);
}