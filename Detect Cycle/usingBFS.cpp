#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

bool detectCycle(int src, vector<int> adj[], int vis[])
{
    vis[src] = 1;
    queue<pair<int, int>> children;
    children.push({src, -1});

    while (!children.empty())
    {
        int node = children.front().first;
        int parent = children.front().second;
        children.pop();

        for (auto adjNode : adj[node])
        {
            if (!vis[adjNode])
            {
                vis[adjNode] = 1;
                children.push({adjNode, node});
            }
            else if (parent != adjNode)
            {
                return true;
            }
        }
    }

    return false;
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
    int vis[n] = {0};

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
    cout << detectCycle(1, adj, vis);

    return 0;
}