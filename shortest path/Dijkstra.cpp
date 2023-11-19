#include <iostream>
#include <vector>
#include <sstream>
#include <Queue>
#include <stack>
using namespace std;
// shortest path
void dijkstra(int src, vector<pair<int, int>> adj[], int dist[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({dist[src], src});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        for (auto edge : adj[node])
        {
            int adjNode = edge.first;
            int edgeWt = edge.second;

            if (distance + edgeWt < dist[adjNode])
            {
                dist[adjNode] = distance + edgeWt;
                pq.push({dist[adjNode], adjNode});
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
        adj[v].push_back({u, w});
    }

    int src;
    cin >> src;

    int dist[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }

    dijkstra(src, adj, dist);

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