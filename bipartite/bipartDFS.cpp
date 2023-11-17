#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

bool isBipartite(vector<int> adj[], int color[], int src, int src_color)
{
    color[src] = !src_color;

    for (auto adjNode : adj[src])
    {
        if (color[adjNode] == -1)
        {
            if (!isBipartite(adj, color, adjNode, !src_color))
            {
                return false;
            }
        }
        else if (color[adjNode] == color[src])
        {
            return false;
        }
    }

    return true;
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
    vector<int> adj[n];
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

    int color[n];
    // color[n] = {-1} does not work, it works only for 0
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    bool isBp = true;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!isBipartite(adj, color, i, 1))
            {
                isBp = false;
                break;
            }
        }
    }

    if (isBp)
    {
        cout << "Bipartite";
    }
    else
    {
        cout << "Not Bipartite";
    }

    return 0;
}