#include <iostream>
#include <vector>
#include <sstream>
#include <Queue>
#include <stack>
using namespace std;
// shortest path
void topo(int src, vector<pair<int, int>> adj[], int vis[], stack<int> &sorted)
{
    vis[src] = 1;

    for (auto it : adj[src])
    {
        if (!vis[it.first])
        {
            topo(it.first, adj, vis, sorted);
        }
    }

    sorted.push(src);
}

int main()
{
    int n, m;
    string nodes;
    getline(cin, nodes);
    stringstream num(nodes);
    num >> n;
    num >> m;

    // adj list
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        string edge;
        getline(cin >> ws, edge);
        stringstream node(edge);
        int u, v, w;
        node >> u;
        node >> v;
        node >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back(u);
    }

    int src;
    cin >> src;

    int vis[n] = {0};
    stack<int> sorted;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            topo(i, adj, vis, sorted);
    }

    vector<int> dist(n, INT_MAX);

    while (sorted.top() != src)
    {
        sorted.pop();
    }
    dist[src] = 0;

    while (!sorted.empty())
    {
        int node = sorted.top();
        sorted.pop();

        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;

            if (dist[node] + wt < dist[v])
            {
                dist[v] = dist[node] + wt;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INT_MAX)
        {
            cout << "inf ";
            continue;
        }
        cout << dist[i] << " ";
    }

    return 0;
}