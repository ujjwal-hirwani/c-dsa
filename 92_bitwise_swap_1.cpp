// USP
#include <iostream>
using namespace std;

int main()
{
	unsigned int a = 50, b = 99;
	cout << "Before swapping" << endl;
	cout << "a = " << a << endl << "b = " << b << endl;
	a = a ^ b;
    b = a ^ b;
    a = a ^ b;
	cout << "After swapping" << endl;
	cout << "a = " << a << endl << "b = " << b << endl;
	return 0;
}