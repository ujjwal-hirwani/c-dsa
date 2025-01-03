// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second < p2.second;
}
int maxEvents(vector<vector<int>> &events)
{
	int n = events.size();
	vector<pair<int, int>> event(n);
	for (int i = 0; i < n; i++)
	{
		event[i] = make_pair(events[i][0], events[i][1]);
	}
	sort(event.begin(), event.end(), compare);
	for (int i = 0; i < n; i++)
	{
		cout << event[i].first << event[i].second << endl;
	}
	return 0;
}
int main()
{
	vector<vector<int>> events = {{1, 2}, {3, 4}, {2, 3}};
	cout << maxEvents(events) << endl;
	return 0;
}