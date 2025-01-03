// USP
// In this variation we need to print the order of jobs selected.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Job
{
    public:
    int idx;
    int deadline;
    int profit;

    Job(int idx, int deadline, int profit)
    {
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};
int maxProfit(vector<pair<int, int>> pairs)
{
    vector<Job> jobs;
    for (int i = 0; i < pairs.size(); i++)
    {
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);
    }
    sort(jobs.begin(), jobs.end(), [](Job a, Job b){ // lambda function.
        return a.profit > b.profit;
    });
    int profit = jobs[0].profit;
    int safeDeadline = 2;
    cout << "Job: " << jobs[0].idx << endl;
    for (int i = 1; i < jobs.size(); i++)
    {
        if (jobs[i].deadline >= safeDeadline)
        {
            cout << "Job: " << jobs[i].idx << endl;
            profit += jobs[i].profit;
            safeDeadline = jobs[i].deadline;
        }
    }
    return profit;
}
int main()
{
    vector<pair<int, int>> jobs;
    jobs.push_back(make_pair(4, 20)); // deadline, profit
    jobs.push_back(make_pair(1, 10));
    jobs.push_back(make_pair(1, 40));
    jobs.push_back(make_pair(1, 30));

    cout << maxProfit(jobs) << endl;
    return 0;
}