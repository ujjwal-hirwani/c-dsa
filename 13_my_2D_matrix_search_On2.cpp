// USP
// This is actually O(n^2) because we are just expanding our matrix.
// single for loop doesnot mean O(n)
// This program will rum n * m times in worst case which is same as in the case oof nested for loops.
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
bool search(int mat[4][4], int n, int m, int key) // n row, m col;
{
    int *ptr = &mat[0][0];
    int pos = -1;
    for (int i = 0; i < n * m; i++)
    {
        if (ptr[i] == key)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
        return false;
    else
    {
        cout << "Element found at: " << pos / m << ", " << pos % m <<endl;
        return true;
    }
}