// USP
# include <iostream>
using namespace std;
int friend_pairing(int n);
int main()
{
    cout << friend_pairing(4) << endl;
    return 0;
}
int friend_pairing(int n)
{
    if (n == 1 || n == 0)
        return 1;
    return friend_pairing(n - 1) + ((n - 1) * friend_pairing(n - 2));
}