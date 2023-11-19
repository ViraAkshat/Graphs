#include <iostream>
#include <vector>
#include <sstream>
#include <Queue>
#include <stack>
using namespace std;
// shortest path
void shortest(int src, vector<int> adj[], int dist[])
{
    queue<int> nodeDist;
    nodeDist.push(src);
    dist[src] = 0;

    while (!nodeDist.empty())
    {
        int node = nodeDist.front();
        nodeDist.pop();

        for (auto adjNode : adj[node])
        {
            if (dist[node] + 1 < dist[adjNode])
            {
                dist[adjNode] = dist[node] + 1;
                nodeDist.push(adjNode);
            }
        }
    }
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

    int src;
    cin >> src;

    int dist[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    shortest(src, adj, dist);

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