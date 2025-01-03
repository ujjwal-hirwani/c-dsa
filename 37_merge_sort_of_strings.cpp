// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int inversion_count(vector <int> nums);
int main()
{
    vector <int> nums = {2,4,1,3,5};
    cout << inversion_count(nums) << endl;
    return 0;
}
int inversion_count(vector <int> nums)
{
    int count = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[i])
                count ++;
        }
    }
    return count;
}