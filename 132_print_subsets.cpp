// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> subset)
{
    for (int i = 0; i < subset.size(); i++)
    {
        cout << subset[i] << "\t";
    }
    cout << endl;
}
void print_subsets(vector<int> nums, vector<int> subset)
{
    if (nums.size() == 0)
    {
        print(subset);
        return;
    }
    int num = nums[nums.size() - 1];
    nums.pop_back();
    print_subsets(nums, subset);
    subset.push_back(num);
    print_subsets(nums, subset);
}
int main()
{
    vector<int> nums = {3, 6, 2, 7, 1, 9};
    vector<int> subset;
    print_subsets(nums, subset);
    return 0;
}