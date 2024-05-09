#include <iostream>
#include <vector>

using namespace std;

const int INF = 999;

int minCostEdge(int n, const vector<int> &minCost, const vector<bool> &visited)
{
    int minCostEdge = -1;
    int minCostValue = INF;

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i] && minCost[i] < minCostValue)
        {
            minCostValue = minCost[i];
            minCostEdge = i;
        }
    }

    return minCostEdge;
}

vector<pair<int, int>> primMST(const vector<vector<int>> &graph, int n)
{
    vector<bool> visited(n, false);
    vector<int> minCost(n, INF);
    vector<int> parent(n, -1);
    vector<pair<int, int>> mst;

    minCost[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; ++count)
    {
        int u = minCostEdge(n, minCost, visited);
        if (u == -1)
            break;

        visited[u] = true;

        if (parent[u] != -1)
            mst.push_back({parent[u], u});

        for (int v = 0; v < n; ++v)
        {
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < minCost[v])
            {
                minCost[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    return mst;
}

int main()
{
    int n = 4;
    vector<vector<int>> graph = {
        {0, 1, 3, 4},
        {1, 0, 2, 0},
        {3, 2, 0, 5},
        {4, 0, 5, 0}};

    vector<pair<int, int>> mst = primMST(graph, n);

    int totalCost = 0;
    cout << "Minimum Spanning Tree (MST) edges:" << endl;
    for (auto &edge : mst)
    {
        cout << edge.first << " - " << edge.second << endl;
        totalCost += graph[edge.first][edge.second];
    }
    cout << "Total cost of MST: " << totalCost << endl;

    return 0;
}