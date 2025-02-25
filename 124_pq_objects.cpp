// USP
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class student
{
    public:
    string name;
    int marks;

    student(string name, int marks)
    {
        this->name = name;
        this->marks = marks;
    }
    bool operator< (const student& s) const
    {
        return this->marks < s.marks;
    }
};

int main()
{
    priority_queue<student> pq;
    pq.push(student("Ujjwal", 500));
    pq.push(student("Nitin", 1000));
    pq.push(student("Aradhya", 600));

    while (!pq.empty())
    {
        cout << pq.top().name << " " << pq.top().marks << endl;
        pq.pop();
    }
    return 0;
}