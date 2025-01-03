// USP
#include <iostream>
using namespace std;
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int start = 0;
    int end = n-1;
    while (start < end)
    {
        swap(a[start], a[end]);
        start ++;
        end --;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}