// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second < p2.second;
}
int main()
{
	vector<int> start = {0, 1, 2};
	vector<int> end = {9, 2, 4};
	vector<pair<int, int>> pairs(start.size(), make_pair(0, 0));
	for (int i = 0; i < start.size(); i++)
	{
		pairs[i] = make_pair(start[i], end[i]);
	}
	// if we want to sort the pair in ascending order of end time.
	sort(pairs.begin(), pairs.end(), compare);
	for (int i = 0; i < start.size(); i++)
	{
		cout << "A" << i << ": (" << pairs[i].first << ", " << pairs[i].second << ")" << endl;
	}
	return 0;
}