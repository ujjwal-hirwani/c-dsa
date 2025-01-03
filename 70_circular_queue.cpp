// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Queue
{
    int *arr;
    int f, r, capacity, size;

public:
    Queue(int capacity)
    {
        arr = new int[capacity];
        this->capacity = capacity;
        f = 0;
        r = -1;
        size = 0;
    }
    void push(int val)
    {
        if (size == capacity)
        {
            cout << "Queue is full !!!" << endl;
            return;
        }
        r = (r + 1) % capacity;
        arr[r] = val;
        size++;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is empty !!!" << endl;
            return;
        }
        f = (f + 1) % capacity;
        size--;
    }
    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty !!!" << endl;
            return -1;
        }
        return arr[f];
    }
    bool isEmpty()
    {
        return size == 0;
    }
};
int main()
{
    Queue q(3);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    q.pop();
    return 0;
}