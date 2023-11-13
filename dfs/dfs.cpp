#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, ls);
        }
    }
}

void dfsOnGraph(int n, vector<int> adj[])
{
    int vis[n] = {0};
    int start = 0;
    vector<int> ls;

    dfs(start, adj, vis, ls);

    for (int i = 0; i < ls.size(); i++)
    {
        cout << ls[i] << " ";
    }
}

int main()
{
    int n, m; // nodes and edges
    string line;
    getline(cin, line);
    stringstream words(line);

    words >> n;
    words >> m;

    // insert graph; adjacency list; O(2*Edges)
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        // cout << i << " ";

        int u, v;
        getline(cin >> ws, line);
        stringstream pts(line);
        pts >> u;
        pts >> v;
        // cout << "u: " << u << "v: " << v << endl;
        adj[u].push_back(v); // add a tuple in case of weighted graphs, (v, wt)
        adj[v].push_back(u); // skip in case of directed graph
        // cout << "end of " << i << endl;
    }

    // bfs on the graph
    dfsOnGraph(n, adj);

    return 0;
}