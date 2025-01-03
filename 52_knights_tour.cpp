// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void knights_tour(vector<vector<int>>& board, int row, int col, int count);
void print(vector<vector<int>>& board);
int main()
{
    int n = 5;
    vector<vector<int>> board;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(n, -1);
        board.push_back(temp);
    }
    knights_tour(board, 0, 0, 0);
    return 0;
}
void print(vector<vector<int>>& board)
{
    cout << ".................................." << endl;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
void knights_tour(vector<vector<int>>& board, int row, int col, int count)
{
    if (count == board.size() * board.size())
    {
        print(board);
        return;
        // to print only one solution exit(0).
    }
    if (row < 0 || row >= board.size() || col < 0 || col >= board.size())
        return;
    if (board[row][col] >= 0)
        return;
    board[row][col] = count;
    knights_tour(board, row - 2, col + 1, count + 1);
    knights_tour(board, row - 1, col + 2, count + 1);
    knights_tour(board, row + 1, col + 2, count + 1);
    knights_tour(board, row + 2, col + 1, count + 1);
    knights_tour(board, row + 2, col - 1, count + 1);
    knights_tour(board, row + 1, col - 2, count + 1);
    knights_tour(board, row - 1, col - 2, count + 1);
    knights_tour(board, row - 2, col - 1, count + 1);
    board[row][col] = -1;
}