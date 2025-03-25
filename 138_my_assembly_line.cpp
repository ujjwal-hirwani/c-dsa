// USP
// my approach for constructing the optimal path.
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void assembly_line_scheduling(vector<int> e, vector<int> x, vector<vector<int>> a, vector<vector<int>> t)
{
    int n = a[0].size();
    vector<vector<int>> f(2, vector<int>(n, 0));
    vector<vector<int>> l(2, vector<int>(n, -1));

    // initializing the dp table.
    f[0][0] = a[0][0] + e[0];
    f[1][0] = a[1][0] + e[1];

    for (int i = 1; i < n; i++)
    {
        if (f[0][i - 1] <= f[1][i - 1] + t[1][i - 1])
        {
            f[0][i] = f[0][i - 1] + a[0][i];
            l[0][i] = 0;
        }
        else
        {
            f[0][i] = f[1][i - 1] + t[1][i - 1] + a[0][i];
            l[0][i] = 1;
        }
        if (f[1][i - 1] <= f[0][i - 1] + t[0][i - 1])
        {
            f[1][i] = f[1][i - 1] + a[1][i];
            l[1][i] = 1;
        }
        else
        {
            f[1][i] = f[0][i - 1] + t[0][i - 1] + a[1][i];
            l[1][i] = 0;
        }
    }
    int final_cost, last_line;
    if (f[0][n - 1] + x[0] < f[1][n - 1] + x[1])
    {
        final_cost = f[0][n - 1] + x[0];
        last_line = 0;
    }
    else
    {
        final_cost = f[1][n - 1] + x[1];
        last_line = 1;
    }
    cout << "Minimum time to travel in the assembly line: " << final_cost << endl;
    cout << "Optimal path: " << endl;
    int i = n - 1;
    stack<int> s;
    s.push(last_line);
    int row = last_line;
    while (i > 0)
    {
        s.push(l[row][i]);
        row = l[row][i];
        i--;
    }
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}
int main()
{
    vector<int> e = {2, 4}; // Entry times for both lines
    vector<int> x = {3, 2}; // Exit times for both lines
    vector<vector<int>> a = {{7, 9, 3, 4, 8, 4}, {8, 5, 6, 4, 5, 7}}; // Processing times
    vector<vector<int>> t = {{2, 3, 1, 3, 4}, {2, 1, 2, 2, 1}}; // Transition times
    assembly_line_scheduling(e, x, a, t);
    return 0;
}