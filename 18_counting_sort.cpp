// USP
#include <iostream>
#include "ujjwal.h"
using namespace std;

int main()
{
    int a[] = {1, 4, 1, 3, 2, 4, 3, 7};
    int n = sizeof(a) / sizeof(int);
    int freq[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    int k = 0;
    print_array(freq, n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        while (freq[i] != 0)
        {
            a[k++] = i;
            freq[i]--;
        }
    }
    print_array(a, n);
    return 0;
}