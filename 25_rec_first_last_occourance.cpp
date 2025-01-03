// USP
#include <iostream>
using namespace std;
int first_occourance(int a[], int i, int n, int target);
int last_occourance(int a[], int i, int target);
int main()
{
    int a[10] = {1, 2, 8, 5, 3, 6, 7, 3, 9};
    cout << first_occourance(a, 0, sizeof(a)/sizeof(int), 3) << endl;
    cout << last_occourance(a, sizeof(a)/sizeof(int) - 1, 99) << endl;
    return 0;
}
int first_occourance(int a[], int i, int n, int target)
{
    if (i == n)
        return -1;
    if (a[i] == target)
        return i;
    return first_occourance(a, i + 1, n, target);
}
int last_occourance(int a[], int i, int target)
{
    if (i == -1)
        return -1;
    if (a[i] == target)
        return i;
    return last_occourance(a, i - 1, target);
}