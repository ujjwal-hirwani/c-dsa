// USP
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        vector<int> vec(n);
        vector<vector<int>> mat;
        if (original.size() == m * n)
            return mat;
        int count = 0;
        for (int i = 0; i < original.size(); i++)
        {
            vec[count] = original[i];
            count++;
            if (count == n)
            {
                mat.push_back(vec);
                count = 0;
            }
        }
        return mat;
    }
};
int main()
{
    Solution s;
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    vector<vector<int>> m;
    m = s.construct2DArray(a, 4, 4);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}