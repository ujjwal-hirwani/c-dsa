// USP
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int maxAreaHistogram(vector<int> heights)
{
	vector<int> nsl(heights.size()); //next smaller left
	vector<int> nsr(heights.size()); //next smaller right
	stack<int> s;
	for(int i = 0; i < heights.size(); i++)
	{
		while(!s.empty() && heights[i] <= heights[s.top()])
			s.pop();
		if (s.empty())
			nsl[i] = -1;
		else
			nsl[i] = s.top();
		s.push(i);
	}
	while (!s.empty())
	{
		s.pop();
	}
	for(int i = heights.size() - 1; i >= 0; i--)
	{
		while(!s.empty() && heights[i] <= heights[s.top()])
			s.pop();
		if (s.empty())
			nsr[i] = heights.size();
		else
			nsr[i] = s.top();
		s.push(i);
	}
	int maxArea = INT32_MIN;
	for (int i = 0; i < heights.size(); i++)
	{
		int length = heights[i];
		int width = nsr[i] - nsl[i] - 1;
		int area = length * width;
		maxArea = max(area, maxArea);
	}
	return maxArea;
}
int main()
{
	vector<int> heights = {2, 1, 5, 6, 2, 3};
	cout << maxAreaHistogram(heights) << endl;
	return 0;
}