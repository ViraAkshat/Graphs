#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
// detect cycle in a directed graph using DFS
// this case is different than that for undirected graph

bool detectCycle(int src, vector<int> adj[], int vis[])
{
    // using DFS
    vis[src] = 2; // visited and path visited (1+1)

    for (auto adjNode : adj[src])
    {
        if (vis[adjNode] == 0)
        {
            if (detectCycle(adjNode, adj, vis))
            {
                return true;
            }
        }
        else if (vis[adjNode] == 2)
        {
            return true;
        }
    }

    vis[src] = 1;

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
        // adj[d2].push_back(d1);
    }

    int vis[n] = {0};
    bool isCycle = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (detectCycle(i, adj, vis))
            {
                isCycle = true;
                break;
            }
        }
    }

    if (isCycle)
    {
        cout << "There is a cycle";
    }
    else
    {
        cout << "No cycle";
    }

    return 0;
}