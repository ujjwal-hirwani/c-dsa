#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void assembly_line_scheduling(vector<int> e, vector<int> x, vector<vector<int>> a, vector<vector<int>> t)
{
    int n = a[0].size(); // Number of stations
    vector<vector<int>> f(2, vector<int>(n, 0)); // DP table for min cost
    vector<vector<int>> l(2, vector<int>(n, -1)); // DP table for path tracking

    // Base case: Entry time + first station processing time
    f[0][0] = e[0] + a[0][0];
    f[1][0] = e[1] + a[1][0];

    // Fill DP table
    for (int j = 1; j < n; j++)
    {
        // Compute cost for line 1
        if (f[0][j - 1] <= f[1][j - 1] + t[1][j - 1])
        {
            f[0][j] = f[0][j - 1] + a[0][j];
            l[0][j] = 0; // Came from same line
        }
        else
        {
            f[0][j] = f[1][j - 1] + t[1][j - 1] + a[0][j];
            l[0][j] = 1; // Came from other line
        }

        // Compute cost for line 2
        if (f[1][j - 1] <= f[0][j - 1] + t[0][j - 1])
        {
            f[1][j] = f[1][j - 1] + a[1][j];
            l[1][j] = 1; // Came from same line
        }
        else
        {
            f[1][j] = f[0][j - 1] + t[0][j - 1] + a[1][j];
            l[1][j] = 0; // Came from other line
        }
    }

    // Compute final cost with exit times
    int final_cost, last_line;
    if (f[0][n - 1] + x[0] <= f[1][n - 1] + x[1])
    {
        final_cost = f[0][n - 1] + x[0];
        last_line = 0;
    }
    else
    {
        final_cost = f[1][n - 1] + x[1];
        last_line = 1;
    }

    cout << "Minimum Assembly Line Time: " << final_cost << endl;

    // Reconstruct the optimal path
    vector<int> path(n);
    path[n - 1] = last_line;
    for (int j = n - 1; j > 0; j--)
    {
        path[j - 1] = l[path[j]][j];
    }

    // Print optimal path
    cout << "Optimal Path: ";
    for (int j = 0; j < n; j++)
    {
        cout << "Line " << path[j] + 1 << " -> ";
    }
    cout << "Exit" << endl;
}

int main()
{
    vector<int> e = {2, 2}; // Entry times for both lines
    vector<int> x = {3, 2}; // Exit times for both lines
    vector<vector<int>> a = {{7, 9, 3, 4, 8, 4}, {8, 5, 6, 4, 5, 7}}; // Processing times
    vector<vector<int>> t = {{2, 3, 1, 3, 4}, {2, 1, 2, 2, 1}}; // Transition times

    assembly_line_scheduling(e, x, a, t);
    return 0;
}
