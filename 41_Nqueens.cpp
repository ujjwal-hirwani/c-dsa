// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Nqueens(vector<vector<char>> board, int row);
bool isSafe(vector<vector<char>> board, int row, int col);
void print(vector<vector<char>> board);
int main()
{
    int n = 8;
    vector<vector<char>> board;
    for (int i = 0; i < n; i++)
    {
        vector<char> vec;
        for (int j = 0; j < n; j++)
        {
            vec.push_back('.');
        }
        board.push_back(vec);
    }
    Nqueens(board, 0);
    return 0;
}
void print(vector<vector<char>> board)
{
    cout << "-----------------------------------------------------------------" << endl;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
void Nqueens(vector<vector<char>> board, int row)
{
    if (row == board.size())
    {
        print(board);
        return;
    }
    for (int j = 0; j < board.size(); j++)
    {
        if (isSafe(board, row, j))
        {
            board[row][j] = 'Q';
            Nqueens(board, row + 1);
            board[row][j] = '.';
        }
    }
}
bool isSafe(vector<vector<char>> board, int row, int col)
{
    // Horizontal safety
    for (int j = 0; j < col; j++)
    {
        if (board[row][j] == 'Q')
            return false;
    }
    // Vertical safety
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }
    // Digonal safety
    // left
    int i = row - 1;
    int j = col - 1;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
            return false;
        i--;
        j--;
    }
    i = row - 1;
    j = col + 1;
    // right
    while (i >= 0 && j < board.size())
    {
        if (board[i][j] == 'Q')
            return false;
        i--;
        j++;
    }
    return true;
}