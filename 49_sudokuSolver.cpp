// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printSudoku(int sudoku[9][9]);
bool isSafe(int sudoku[9][9], int row, int col, int digit);
bool sudokuSolver(int sudoku[9][9], int row, int col);
int main()
{
    int sudoku[9][9] = {{0, 0, 8, 0, 0, 0, 0, 0, 0},
                        {4, 9, 0, 1, 5, 7, 0, 0, 2},
                        {0, 0, 3, 0, 0, 4, 1, 9, 0},
                        {1, 8, 5, 0, 6, 0, 0, 2, 0},
                        {0, 0, 0, 0, 2, 0, 0, 6, 0},
                        {9, 6, 0, 4, 0, 5, 3, 0, 0},
                        {0, 3, 0, 0, 7, 2, 0, 0, 4},
                        {0, 4, 9, 0, 3, 0, 0, 5, 7},
                        {8, 2, 7, 0, 0, 9, 0, 1, 3}};
    cout << sudokuSolver(sudoku, 0, 0) << endl;
    return 0;
}
void printSudoku(int sudoku[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}
bool sudokuSolver(int sudoku[9][9], int row, int col)
{
    if (row == 9)
    {
        printSudoku(sudoku);
        return true;
    }
    int nxtrow = row;
    int nxtcol = col + 1;
    if (col == 8)
    {
        nxtrow = row + 1;
        nxtcol = 0;
    }
    if (sudoku[row][col] != 0)
    {
        // call for next cell.
        return sudokuSolver(sudoku, nxtrow, nxtcol);
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (isSafe(sudoku, row, col, i))
            {
                sudoku[row][col] = i;
                if (sudokuSolver(sudoku, nxtrow, nxtcol))
                    return true;
                sudoku[row][col] = 0;
            }
        }
    }
    return false;
}
bool isSafe(int sudoku[9][9], int row, int col, int digit)
{
    for (int i = 0; i <= 8; i++)
    {
        if (sudoku[i][col] == digit)
            return false;
    }
    for (int j = 0; j <= 8; j++)
    {
        if (sudoku[row][j] == digit)
            return false;
    }
    int start_row = (row / 3) * 3;
    int start_col = (col / 3) * 3;
    for (int i = start_row; i < start_row + 3; i++)
    {
        for (int j = start_col; j < start_col + 3; j++)
        {
            if (sudoku[i][j] == digit)
                return false;
        }
    }
    return true;
}