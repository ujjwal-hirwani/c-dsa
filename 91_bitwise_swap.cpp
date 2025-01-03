// USP
#include <iostream>
using namespace std;

int main()
{
	unsigned int a = 12345, b = 54321;
	cout << "Before swapping" << endl;
	cout << "a = " << a << endl << "b = " << b << endl;
	unsigned int mask = 1 << 31;
	for (int i = 0; i < 32; i++)
	{
		unsigned int a1 = a & mask;
		unsigned int b1 = b & mask;
		a = (a << 1);
		b = (b << 1);
		a = a | (b1 >> 31);
		b = b | (a1 >> 31);
	}
	cout << "After swapping" << endl;
	cout << "a = " << a << endl << "b = " << b << endl;
	return 0;
}