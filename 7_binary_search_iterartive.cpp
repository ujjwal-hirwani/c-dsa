// USP
#include <iostream>
using namespace std;
int binary_search(int a[], int n, int val)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (a[mid] == val)
        {
            return mid;
        }
        else if(a[mid] < val)
        {
            start = mid + 1;
        }
        else if(a[mid] > val)
        {
            end = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << binary_search(a, 10, 7) << endl;
}