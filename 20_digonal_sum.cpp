// USP
#include <iostream>
using namespace std;

int main()
{
    // int matrix[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = 3;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += matrix[i][i];
        if (i != n - i - 1)
            sum += matrix[i][n - i - 1];
    }
    cout << sum << endl;
    return 0;
}