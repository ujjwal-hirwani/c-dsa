// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Nknights(vector<vector<char>> board, int row);
void print(vector<vector<char>> board);
bool isSafe(vector<vector<char>> board, int row, int col);
int main()
{
    int n = 4;
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
    Nknights(board, 0);
    return 0;
}
void Nknights(vector<vector<char>> board, int row)
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
            board[row][j] = 'K';
            Nknights(board, row + 1);
            board[row][j] = '.';
        }
    }
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
bool isSafe(vector<vector<char>> board, int row, int col)
{
    // check 1
    if ((row - 1 >= 0 && col - 2 >= 0) && (board[row - 1][col - 2] == 'K'))
        return false;
    // check 2
    if ((row - 2 >= 0 && col - 1 >= 0) && (board[row - 2][col - 1] == 'K'))
        return false;
    // check 3
    if ((row - 2 >= 0 && col + 1 < board.size()) && (board[row - 2][col + 1] == 'K'))
        return false;
    // check 4
    if ((row - 1 >= 0 && col + 2 < board.size()) && (board[row - 1][col + 2] == 'K'))
        return false;
    return true;    
}