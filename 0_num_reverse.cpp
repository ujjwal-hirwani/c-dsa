// USP
#include <iostream>
using namespace std;

int main()
{
    int num, rev = 0;
    cout << "Enter any number: ";
    cin >> num;
    while (num != 0)
    {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    cout << "Reversed number: " << rev << endl;
    return 0;
}