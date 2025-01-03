// USP
#include <iostream>
#include "ujjwal.h"
using namespace std;
void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
int main()
{
    int arr[] = {6, 3, 8, 1, 0, 2, 9, 4, 7, 5};
    print_array(arr, 10);
    quick_sort(arr, 0, 9);
    print_array(arr, 10);
    return 0;
}
void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int ind = partition(arr, low, high);
        quick_sort(arr, low, ind - 1);
        quick_sort(arr, ind + 1, high);
    }
}
int partition(int arr[], int low, int high)
{
    int i = low - 1, j = low;
    while (j < high)
    {
        if (arr[j] < arr[high])
            swap(arr[++i], arr[j]); //break and understand.
        j++;
    }
    swap(arr[++i], arr[high]);
    return i;
}