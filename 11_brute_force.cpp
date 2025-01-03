// USP
#include <iostream>
using namespace std;
int max_subarray_sum(int a[], int n);
int main()
{
    int a[] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(a) / sizeof(int);
    int s = max_subarray_sum(a, n);
    cout << "Maximum sum: " << s << endl;
    return 0;
}
int max_subarray_sum(int a[], int n)
{
    int max_sum = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
            }
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}