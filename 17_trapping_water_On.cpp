// USP
#include <iostream>
#include "ujjwal.h"
using namespace std;
int find_trap(int a[], int size);
int main()
{
    int a[] = {4, 2, 0, 6, 3, 2, 5};
    cout << find_trap(a, 7) << endl;
    return 0;
}
int find_trap(int a[], int size)
{
    int l_max[1000000];
    int r_max[1000000];
    l_max[0] = a[0];
    for (int i = 1; i < size; i++)
    {
        l_max[i] = max(l_max[i - 1], a[i]);
    }
    r_max[size - 1] = a[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        r_max[i] = max(r_max[i + 1], a[i]);
    }
    int sum = 0;
    for (int i = 0; i<size; i++)
    {
        int height = min(l_max[i], r_max[i]);
        sum += height - a[i];
    }
    return sum;
}