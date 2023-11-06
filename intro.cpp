#include <iostream>
using namespace std;

int main()
{
    int n, m; // nodes and edges
    cin >> n >> m;

    // insert graph; adjacency matrix O(N^2)
    int adj[n + 1][m + 1] = {0};
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    return 0;
}