// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class activity
{
    public:
    int idx, start, end;
};
bool compare(activity p1, activity p2)
{
    return p1.end < p2.end;
}
int activity_selection(vector<int> start, vector<int> end)
{
    int count = 1;
    vector<activity> activities; // start, end;
    for (int i = 0; i < start.size(); i++)
    {
        activity a;
        a.idx = i;
        a.start = start[i];
        a.end = end[i];
        activities.push_back(a);
    }
    
    sort(activities.begin(), activities.end(), compare);
    cout << "Activity " << 0 << endl;
    int currEnd = activities[0].end;
    for (int i = 1; i < start.size(); i++)
    {
        if (start[i] >= currEnd)
        {
            cout << "Activity " << i << endl;
            count++;
            currEnd = activities[i].end;
        }
    }
    return count;
}
int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    cout << activity_selection(start, end) << endl;
    return 0;
}