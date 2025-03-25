// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longest_common_subsequence(string x, string y, vector<vector<int>>& table)
{
    int row = table.size(), col = table[0].size();
    for (int i = 0; i < row; i++)
    {
        table[i][0] = 0;
    }
    for (int j = 0; j < col; j++)
    {
        table[0][j] = 0;
    }
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (x[i - 1] == y[j - 1])
                table[i][j] = table[i - 1][j - 1] + 1;
            else
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }
    cout << "Length of longest common subsequence = " << table[row - 1][col - 1] << endl;
    int i = row - 1, j = col - 1;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (table[i][j - 1] == table[i][j])
            j--;
        else
        {
            ans = y[j - 1] + ans;
            i--;
            j--;
        }
    }
    cout << "Longest common subsequence: " << ans << endl;

}
int main()
{
    string x, y;
    cout << "Enter first string: ";
    cin >> x;
    cout << "Enter second string: ";
    cin >> y;
    int x_size = x.size(), y_size = y.size();
    vector<vector<int>> table(x_size + 1, vector<int>(y_size + 1, -1));
    longest_common_subsequence(x, y, table);
    return 0;
}