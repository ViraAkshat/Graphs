#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

bool detectCycle(int src, vector<int> adj[], int vis[], int parent)
{
    // using DFS
    vis[src] = 1;

    for (auto adjNode : adj[src])
    {
        if (!vis[adjNode])
        {
            detectCycle(adjNode, adj, vis, src);
        }
        else if (adjNode != parent)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int n, m;
    string line;
    getline(cin, line);
    stringstream nums(line);
    nums >> n;
    nums >> m;
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        string edge;
        getline(cin, edge);
        int d1, d2;
        stringstream nodes(edge);
        nodes >> d1;
        nodes >> d2;
        adj[d1].push_back(d2);
        adj[d2].push_back(d1);
    }

    int vis[n] = {0};
    bool isCycle = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (detectCycle(i, adj, vis, -1))
            {
                isCycle = true;
                break;
            }
        }
    }

    cout << isCycle;

    return 0;
}