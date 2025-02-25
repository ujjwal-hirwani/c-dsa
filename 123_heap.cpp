// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class heap
{
    public:
    vector<int> vec;

    void push(int val)
    {
        // step 1: Insert val at the end.
        vec.push_back(val);
        // step 2: fix the heap.
        int idx = vec.size() - 1;
        int parent = (idx - 1) / 2;
        while (parent >= 0 && vec[parent] < vec[idx])
        {
            swap(vec[parent], vec[idx]);
            idx = parent;
            parent = (idx - 1) / 2;
        }
    }
    void heapify(int idx)
    {
        if (idx >= vec.size())
            return;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int max_idx = idx;

        if (left < vec.size() && vec[left] > vec[max_idx])
            max_idx = left;

        if (right < vec.size() && vec[right] > vec[max_idx])
            max_idx = right;

        swap(vec[idx], vec[max_idx]);

        if (idx != max_idx)
            heapify(max_idx);
    }
    void pop()
    {
        // step 1: swap the root with the last element.
        swap(vec[0], vec[vec.size() - 1]);
        // step 2: delete the last element.
        vec.pop_back();
        // step 3: fix the heap: heapify
        heapify(0);
    }
    int top()
    {
        return vec[0];
    }
    bool empty()
    {
        if (vec.size() == 0)
            return true;
        return false;
    }
};
int main()
{
    heap h;
    h.push(5);
    h.push(10);
    h.push(2);
    h.push(8);
    h.push(3);
    h.push(9);
    h.push(11);
    while (!h.empty())
    {
        cout << h.top() << "\t";
        h.pop();
    }
    return 0;
}