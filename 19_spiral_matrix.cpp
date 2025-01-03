// USP
#include <iostream>
using namespace std;
void spriral_traverse(int matrix[100][100], int row, int col);
void print_top(int matrix[100][100], int top, int bottom, int left, int right);
int count = 0;
int main()
{
    int matrix[100][100], row, col;
    cout << "Enter number of rows: ";
    cin >> row;
    cout << "Enter number of columns: ";
    cin >> col;
    cout << "Enter matrix elements: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << "Entered matrix: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "Spiral traversal: " << endl;
    spriral_traverse(matrix, row, col);
    return 0;
}
void print_top(int matrix[100][100], int top, int bottom, int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        cout << matrix[top][i] << "\t";
        count ++;
    }
}
void print_bottom(int matrix[100][100], int top, int bottom, int left, int right)
{
    for (int i = right; i >= left; i--)
    {
        cout << matrix[bottom][i] << "\t";
        count ++;
    }
}
void print_left(int matrix[100][100], int top, int bottom, int left, int right)
{
    for (int i = bottom; i >= top; i--)
    {
        cout << matrix[i][left] << "\t";
        count ++;
    }
}
void print_right(int matrix[100][100], int top, int bottom, int left, int right)
{
    for (int i = top; i <= bottom; i++)
    {
        cout << matrix[i][right] << "\t";
        count ++;
    }
}
void spriral_traverse(int matrix[100][100], int row, int col)
{
    int top = 0, bottom = row - 1, left = 0, right = col - 1;
    while (count < row * col)
    {
            print_top(matrix, top, bottom, left, right);
            top++;

            print_right(matrix, top, bottom, left, right);
            right--;
            
            print_bottom(matrix, top, bottom, left, right);
            bottom--;

            print_left(matrix, top, bottom, left, right);
            left++;
    }
    cout << endl;
}