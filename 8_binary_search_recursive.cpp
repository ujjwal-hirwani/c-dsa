// USP
#include <iostream>
using namespace std;
int binary_search(int a[], int low, int high, int val)
{
    int mid = (low + high) / 2;
    if (a[mid] == val)
        return mid;
    if (a[mid] < val)
        return binary_search(a, mid + 1, high, val);
    if (a[mid] > val)
        return binary_search(a, low, mid - 1, val);
    return -1;
}
int main()
{//            0  1  2  3  4  5  6  7  8  9
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << binary_search(a, 0, 9, 7) << endl;
}