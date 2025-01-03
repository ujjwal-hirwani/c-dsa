// USP
// let's print subarrays.
#include <iostream>
using namespace std;
void print_subarrays(int a[], int n);
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(a) / sizeof(int);
    print_subarrays(a, n);
    return 0;
}
void print_subarrays(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << a[k];
            }
            cout << ", ";
        }
        cout << endl;
    }
}