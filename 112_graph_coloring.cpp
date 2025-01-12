#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int v, const vector<vector<int>> &graph, const vector<int> &colors, int color) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] == 1 && colors[i] == color) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(const vector<vector<int>> &graph, int m, vector<int> &colors, int v) {
    if (v == graph.size()) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, colors, c)) {
            colors[v] = c;

            if (graphColoringUtil(graph, m, colors, v + 1)) {
                return true;
            }

            colors[v] = 0;
        }
    }

    return false;
}

void graphColoring(const vector<vector<int>> &graph, int m) {
    vector<int> colors(graph.size(), 0);

    if (graphColoringUtil(graph, m, colors, 0)) {
        cout << "Solution Exists:" << endl;
        for (int color : colors) {
            cout << color << " ";
        }
        cout << endl;
    } else {
        cout << "Solution does not exist" << endl;
    }
}

int main() {
    vector<vector<int>> graph(4, vector<int>(4));
    int m;

    cout << "Enter the adjacency matrix (4x4):" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the number of colors available: ";
    cin >> m;

    graphColoring(graph, m);

    return 0;
}
