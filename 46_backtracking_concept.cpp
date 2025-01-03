// USP
#include <iostream>
#include <vector>
#include <algorithm>
#include "ujjwal.h"
using namespace std;
void store (int a[], int n, int ind, int i);
int main()
{
    int a[10];
    store(a, 5, 0, 1);
    print_array(a, 5);
    return 0;
}
void store (int a[], int n, int ind, int i)
{
    if (i <= n)
    {
        a[ind] = i;
        store(a, n, ind + 1, i + 1);
        a[ind] = -1; // This is backtracking concept.
    }
}