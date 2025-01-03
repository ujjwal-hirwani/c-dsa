// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void rat_in_maze(vector<vector<int>> maze, int row, int col, string ans);
int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    rat_in_maze(maze, 0, 0, "");
    return 0;
}
void rat_in_maze(vector<vector<int>> maze, int row, int col, string ans)
{

    if (row == maze.size() - 1 && col == maze.size() - 1)
    {
        cout << ans << endl;
        return;
    }
    if (row >= maze.size() || col >= maze.size() || row < 0 || col < 0)
        return;
    if (maze[row][col] == 2 || maze[row][col] == 0)
        return;
    maze[row][col] = 2; // mark the travelled cells.
    // left
    rat_in_maze(maze, row, col - 1, ans + 'L');
    // right
    rat_in_maze(maze, row, col + 1, ans + 'R');
    // up
    rat_in_maze(maze, row - 1, col, ans + 'U');
    // down
    rat_in_maze(maze, row + 1, col, ans + 'D');
    maze[row][col] = 1; // backtrack if next step is wrong.
}