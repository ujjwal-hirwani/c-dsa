// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void heapify(int idx, vector<int> &arr, int n)
{
    if (idx >= n)
        return;
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;

    int maxIdx = idx;
    if (left < n && arr[left] > arr[idx])
        maxIdx = left;

    if (right < n && arr[right] > arr[idx])
        maxIdx = right;

    if (idx != maxIdx)
    {
        swap(arr[idx], arr[maxIdx]);
        heapify(maxIdx, arr, n);
    }
}
void heapSort(vector<int> &arr)
{
    // step 1: make a max heap of the given array.
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(i, arr, n);
    }
    // step 2: swap the first element with the last element. heapify rest of the elements.
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
    }
}
int main()
{
    vector<int> arr = {5, 2, 4, 3, 1};
    heapSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
    return 0;
}