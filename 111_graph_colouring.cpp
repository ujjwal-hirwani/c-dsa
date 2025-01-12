#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if it's safe to color a vertex with a given color
bool isSafe(int v, int color, const vector<vector<int>> &graph, const vector<int> &colors) {
    for (size_t i = 0; i < graph.size(); i++) {
        if (graph[v][i] == 1 && colors[i] == color) {
            return false; // Adjacent vertex has the same color
        }
    }
    return true;
}

// Recursive function to color the graph
bool graphColoringUtil(const vector<vector<int>> &graph, int m, vector<int> &colors, int v) {
    if (v == graph.size()) {
        return true; // All vertices are colored
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c, graph, colors)) {
            colors[v] = c;

            if (graphColoringUtil(graph, m, colors, v + 1)) {
                return true;
            }

            // Backtrack
            colors[v] = 0;
        }
    }

    return false;
}

// Function to find the chromatic number of a graph
int findChromaticNumber(const vector<vector<int>> &graph) {
    int n = graph.size();
    for (int m = 1; m <= n; m++) {
        vector<int> colors(n, 0);
        if (graphColoringUtil(graph, m, colors, 0)) {
            return m; // Found the chromatic number
        }
    }
    return n; // Worst case: all vertices require different colors
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the adjacency matrix of the graph:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int chromaticNumber = findChromaticNumber(graph);
    cout << "The chromatic number of the graph is: " << chromaticNumber << endl;

    return 0;
}
