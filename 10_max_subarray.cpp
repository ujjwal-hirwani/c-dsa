// USP
#include <iostream>
using namespace std;

void max_subarray(int a[], int n);
int main()
{
    int a[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(a) / sizeof(int);
    max_subarray(a, n);
    return 0;
}
void max_subarray(int a[], int n)
{
    int total = 0, max[n], start, end;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
            }
            if (sum > total)
            {
                total = sum;
                start = i;
                end = j;
                for (int k = i; k <= j; k++)
                {
                    max[k] = a[k];
                }
            }
        }
    }
    cout << "Maximum sum: " << total << endl;
    for (int i = start; i <= end; i++)
    {
        cout << max[i] << "\t";
    }
    cout << endl;
}