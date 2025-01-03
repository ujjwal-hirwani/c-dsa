// USP
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
bool isDuplicate(string str);
int main()
{
	string str1 = "((a+b))";
	string str2 = "((a+b)+(c+d))";
	cout << boolalpha << isDuplicate(str1) << endl;
	cout << boolalpha << isDuplicate(str2) << endl;
	return 0;
}
bool isDuplicate(string str)
{
	stack<char> temp;
	for (char i : str)
	{
		if (i != ')')
			temp.push(i);
		else
		{
			if (temp.top() == '(')
				return true;
			while (temp.top() != '(')
			{
				temp.pop();
			}
			temp.pop();
		}
	}

	return false;
}