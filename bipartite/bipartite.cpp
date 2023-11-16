#include <iostream>
#include <vector>
#include <sstream>
#include <Queue>
using namespace std;

bool isBipartite(vector<int> adj[], int color[])
{
    queue<int> bipart;
    bipart.push(0);
    color[0] = 0;

    while (!bipart.empty())
    {
        int node = bipart.front();
        bipart.pop();
        for (auto adjNode : adj[node])
        {
            if (color[adjNode] == -1)
            {
                color[adjNode] = !color[node];
                bipart.push(adjNode);
            }
            else if (color[adjNode] == color[node])
            {
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
    int color[n] = {-1};

    cout << isBipartite(adj, color);

    return 0;
}