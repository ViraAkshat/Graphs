#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

bool detectCycle(int src, vector<int> adj[], int vis[])
{
    vis[src] = 1;
    queue<pair<int, int>> nextNode;
    nextNode.push({src, -1}); // node, parent

    while (!nextNode.empty())
    {
        int current_node = nextNode.front().first;
        int parent = nextNode.front().second;
        nextNode.pop();

        for (auto adjNode : adj[current_node])
        {
            if (!vis[adjNode])
            {
                vis[adjNode] = 1;
                nextNode.push({adjNode, current_node});
            }
            else if (adjNode != parent)
            {
                return true;
            }
        }
    }

    return false;
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
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        string edge;
        getline(cin >> ws, edge);
        stringstream node(edge);
        int u, v;
        node >> u;
        node >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int vis[n] = {0};
    bool isCycle = false;

    // to account for multiple connected components
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

    cout << isCycle;

    return 0;
}