// USP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_optimal_parenthesization(vector<vector<int>>& s, int i, int j, char& name)
{
    if (i == j)
    {
        cout << name++;
        return;
    }
    cout << "(";
    print_optimal_parenthesization(s, i, s[i][j], name);
    print_optimal_parenthesization(s, s[i][j] + 1, j, name);
    cout << ")";
}

void matrix_chain_multiplication(vector<vector<int>>& matrices)
{
    int n = matrices.size();
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, -1));
    vector<int> p;
    p.push_back(matrices[0][0]);
    for (int i = 0; i < n; i++)
    {
        p.push_back(matrices[i][1]);
    }

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            m[i][j] = INT32_MAX;
            for (int k = i; k < j; k++)
            {
                int cost = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of multiplication: " << m[0][n - 1] << endl;

    cout << "Optimal parenthasization: " << endl;
    char name = 'A';
    print_optimal_parenthesization(s, 0, n - 1, name);
    cout << endl;
}
int main()
{
    int n = 6;
    vector<vector<int>> matrices = {{30, 35}, {35, 15}, {15, 5}, {5, 10}, {10, 20}, {20, 25}};
    matrix_chain_multiplication(matrices);
    return 0;
}