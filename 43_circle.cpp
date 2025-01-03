// USP
// Program to print circlar star pattern.
#include <iostream>
#include <math.h>
using namespace std;
bool check_length(int r, int i, int j);
int main()
{
    int r;
    cout << "Enter radius: ";
    // for better results input number > 12
    cin >> r;
    for (int i = 0; i <= r * 2; i++)
    {
        for (int j = 0; j <= r * 2; j++)
        {
            if (check_length(r, i, j))
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
bool check_length(int r, int i, int j)
{
    float len = (float)sqrt((pow((i - r), 2)) + (pow((j - r), 2)));
    if ((len < (r + 0.5)) && (len > (r - 0.5))) // pixels are not similar to points in a cartesian plane.
        // considering a range of length as it is not always possible to place a point at the exact location due to spacing and line gap provided by c++.
        return true;
    return false;
}