// USP
#include <iostream>
#include "ujjwal.h"
using namespace std;
void merge_sort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
int main()
{
    int arr[] = {6, 3, 8, 1, 0, 2, 9, 4, 7, 5};
    print_array(arr, 10);
    merge_sort(arr, 0, 9);
    print_array(arr, 10);
    return 0;
}
void merge_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
void merge(int arr[], int low, int mid, int high)
{
    int temp[100];
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] > arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}