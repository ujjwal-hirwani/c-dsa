// USP
#include <iostream>
#include <vector>
using namespace std;

// Function to check if it's safe to color vertex v with color i
bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int i, int V)
{
    for (int k = 0; k < V; k++)
    {
        if (graph[v][k] && color[k] == i)
            return false;
    }
    return true;
}

// Recursive function to solve the graph coloring problem
bool graphColorUntil(vector<vector<int>>& graph, int m, vector<int>& color, int v, int V)
{
    if (v == V)
        return true; // All vertices are successfully colored
    
    for (int i = 0; i < m; i++)
    {
        if (isSafe(v, graph, color, i, V))
        {
            color[v] = i; // Assign color to vertex
            
            if (graphColorUntil(graph, m, color, v + 1, V))
                return true; // If successful, return true
            
            color[v] = -1; // Backtrack
        }
    }
    return false; // No valid coloring found
}

// Function to solve the graph coloring problem
void solveGraphColoring(vector<vector<int>>& graph, int V, int m)
{
    vector<int> colors(V, -1); // Initialize color array with -1 (uncolored)
    
    if (graphColorUntil(graph, m, colors, 0, V))
    {
        cout << "The given graph can be colored with " << m << " colors.\n";
        cout << "The solution is as follows:\n";
        for (int i = 0; i < V; i++)
        {
            cout << "V" << i << ": Color " << colors[i] + 1 << endl;
        }
    }
    else
    {
        cout << "It is not possible to color this graph with " << m << " colors." << endl;
    }
}

int main()
{
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors
    int V = 4; // Number of vertices

    solveGraphColoring(graph, V, m);
    return 0;
}
