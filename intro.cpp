#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m; // nodes and edges
    cin >> n >> m;

    // insert graph; adjacency matrix O(N^2)
    /*    int adj[n + 1][m + 1] = {0};
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u][v] = 1; // equal to weight, in case of weighted graphs
            adj[v][u] = 1; // skip in case of directed graph
        }
    */

    // insert graph; adjacency list; O(2*Edges)
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // add a tuple in case of weighted graphs, (v, wt)
        adj[v].push_back(u); // skip in case of directed graph
    }

    return 0;
}