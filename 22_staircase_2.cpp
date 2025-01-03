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
    cout << boolalpha << search(mat, 4, 4, 45) << endl;
}
bool search(int mat[4][4], int n, int m, int key)
{
    int row = m - 1, col = 0;
    while (col < m && row >= 0)
    {
        if (mat[row][col] == key)
        {
            cout << "Element found at: " << row << ", " << col << endl;
            return true;
        }
        if (mat[row][col] < key)
            col++;
        else
            row--;
    }
    return false;
}