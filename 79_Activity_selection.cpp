// USP
#include <iostream>
#include <vector>


#include <algorithm>
using namespace std;
int maxActivities(vector<int> start, vector<int> end)
{
    // step 1: sorting on the basis of end time.
    // already sorted.
    // choose A0
    int count = 1, currEnd = end[0];
    cout << "Selecting A0" << endl;
    for (int i = 1; i < start.size(); i++)
    {
        if (start[i] >= currEnd)
        {
            cout << "Selecting A" << i << endl;
            count++;
            currEnd = end[i];
        }
    }
    return count;
}
int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    cout << maxActivities(start, end) << endl;
    return 0;
}