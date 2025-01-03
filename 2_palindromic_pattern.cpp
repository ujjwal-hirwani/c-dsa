// USP
#include <iostream>
using namespace std;

int main()
{
    int key, size;
    cout << "Enter pattern size: ";
    cin >> size;
    for (int i = 1; i <= size; i++)
    {
        key = i;
        for (int j = 1; j <= size - i; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << key << " ";
            if (j < (2 * i) / 2)
                key--;
            else
                key++;
        }
        cout << endl;
    }
    return 0;
}