// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class Stack
{
    vector<T> vec;

public:
    void push(T val)
    {
        vec.push_back(val);
    }
    void pop()
    {
        if (!isEmpty())
            vec.pop_back();
    }
    T top()
    {
        // if (isEmpty())
        //     return -1;
        return vec[vec.size() - 1];
    }
    bool isEmpty()
    {
        return vec.size() == 0;
    }
};
int main()
{
    Stack<string> s;
    s.push("Ujjwal");
    s.push("Hiwani");
    s.push("Successful");
    for (int i = 0; i < 3; i++)
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}