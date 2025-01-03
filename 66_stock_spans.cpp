// USP
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> stockSpans(vector<int> &stocks)
{
	stack<int> idx;
	vector<int> spans(stocks.size(), 0);
	spans[0] = 1;
	idx.push(0);
	for (int i = 1; i < stocks.size(); i++)
	{
		int currVal = stocks[i];
		while (!idx.empty() && currVal >= stocks[idx.top()])
		{
			idx.pop();
		}
		if (idx.empty())
			spans[i] = i + 1;
		else
		{
			spans[i] = i - idx.top();
		}
		idx.push(i);
	}
	return spans;
}
int main()
{
	vector<int> stocks = {100, 80, 60, 70, 60, 85, 100};
	vector<int> spans = stockSpans(stocks);
	for (int i = 0; i < spans.size(); i++)
	{
		cout << spans[i] << "\t";
	}
	cout << endl;
	return 0;
}