#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool isF(vector<int>& j, vector<int>& w, int idx, int mT)
{
    int js = j.size(), ws = w.size();
    if (idx == js)
        return true;
    for (int i = 0; i < ws; ++i)
    {
        if (w[i] + j[idx] <= mT)
        {
            w[i] += j[idx];
            
            if (isF(j, w, idx + 1, mT))
                return true;
            w[i] -= j[idx];
        }
        if (w[i] == 0) break;
    }
    return false;
}

int minMaxTime(vector<int>& j, int k)
{
    int n = j.size();
    sort(j.rbegin(), j.rend());
    
    int l = j[0];
    int r = accumulate(j.begin(), j.end(), 0);
    int res = r;
    
    while (l <= r)
    {
        int mid = l + (r - 1) / 2;
        vector<int> w(k, 0);
        
        if (isF(j, w, 0, mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> j(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> j[i];
    }
    cin >> k;
    cout << minMaxTime(j, k) << endl;
    return 0;
}