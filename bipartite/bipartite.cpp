#include <iostream>
#include <vector>
#include <sstream>
#include <Queue>
using namespace std;

bool isBipartite(vector<int> adj[], int color[], int src)
{
    queue<int> bipart;
    bipart.push(src);
    color[src] = 0;

    while (!bipart.empty())
    {
        int node = bipart.front();
        bipart.pop();
        for (auto adjNode : adj[node])
        {
            if (color[adjNode] == -1)
            {
                color[adjNode] = 1 - color[node];
                bipart.push(adjNode);
            }
            else if (color[adjNode] == color[node])
            {
                // cout << node << " " << adjNode << endl;
                return false;
            }
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
            if (!isBipartite(adj, color, i))
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