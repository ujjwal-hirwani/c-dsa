// USP
#include <iostream>
using namespace std;
void print_combination(string s, int size, bool key);
int main()
{
    print_combination("", 6, false);
    return 0;
}
void print_combination(string s, int size, bool key)
{
    if (s.length() == size)
    {
        cout << s << endl;
        return;
    }
    if (key == false)
    {
        print_combination(s + '0', size, false);
        print_combination(s + '1', size, true);
    }
    else
        print_combination(s + '0', size, false);
}