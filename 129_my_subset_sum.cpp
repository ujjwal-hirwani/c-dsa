// USP
// subset sum problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_subset(vector<int>& subset)
{
    cout << "{ ";
    for (int i = 0; i < subset.size(); i++)
    {
        cout << subset[i] << " ";
    }
    cout << "}\n";
}
void find_subsets(vector<int>& nums, vector<int>& subset, int idx, int target)
{
    if (target == 0)
    {
        print_subset(subset);
        return;
    }
    for (int i = idx; i < nums.size(); i++)
    {
        if (nums[i] <= target)
        {
            subset.push_back(nums[i]);
            find_subsets(nums, subset, i + 1, target - nums[i]);
            subset.pop_back(); // backtrack
        }
    }
}
int main()
{
    vector<int> nums = {3, 2, 7, 4, 1, 8, 9};
    int target = 6;
    vector<int> subset;
    find_subsets(nums, subset, 0, target);
    return 0;
}