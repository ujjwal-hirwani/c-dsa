// USP
#include <iostream>
using namespace std;
bool search(int mat[4][4], int n, int m, int key);
int main()
{
    int mat[4][4] = {{10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}};
    cout << boolalpha << search(mat, 4, 4, 15) << endl;
}
bool search(int mat[4][4], int n, int m, int key)
{
    int row = 0, col = m - 1;
    while (row < n && col >= 0)
    {
        int cell = mat[row][col];
        if (cell == key)
        {
            cout << row << ", " << col << endl;
            return true;
        }
        if (cell > key)
            col--;
        else
            row++;
    }
    return false;
}