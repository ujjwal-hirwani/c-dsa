// USP
#include <iostream>
#include <vector>
using namespace std;
bool check_sorted(vector<int> a, int i);
int main()
{
    vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> vec2 = {3, 7, 1, 0, 3, 8, 5, 2, 9, 0};
    cout << boolalpha << check_sorted(vec1, 0) << endl;
    cout << boolalpha << check_sorted(vec2, 0) << endl;
    return 0;
}
bool check_sorted(vector<int> a, int i)
{
    if (i == a.size() - 1)
        return true;
    if (a[i + 1] < a[i])
        return false;
    return check_sorted(a, i + 1);
}