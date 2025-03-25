#include <iostream>
#include <vector>
using namespace std;

// Function to print a subset
void printSubset(const vector<int>& subset) {
    cout << "{ ";
    for (int val : subset) {
        cout << val << " ";
    }
    cout << "}" << endl;
}

// Backtracking function to find subsets that sum to m
void findSubsets(vector<int>& nums, vector<int>& subset, int index, int target) {
    if (target == 0) {
        printSubset(subset);
        return;
    }

    for (int i = index; i < nums.size(); ++i) {
        if (nums[i] <= target) {
            subset.push_back(nums[i]);
            findSubsets(nums, subset, i + 1, target - nums[i]);
            subset.pop_back();  // Backtrack
        }
    }
}

int main() {
    int n, target;
    
    // Taking input set size
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    vector<int> nums(n);
    
    // Taking input set elements
    cout << "Enter " << n << " unique non-negative integers: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Taking target sum
    cout << "Enter the target sum (m): ";
    cin >> target;

    vector<int> subset;
    cout << "\nSubsets that sum to " << target << " are:\n";
    
    findSubsets(nums, subset, 0, target);

    return 0;
}
