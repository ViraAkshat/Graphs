#include <iostream>
#include <vector>
#include <sstream>
#include <Queue>
#include <stack>
using namespace std;

// use indegree: no. of incoming edges/nodes
// first, add nodes with indegree zero in the stack
// decrease the indegree contributed by these nodes to other nodes
// check new zero indegrees, repeat

vector<int> topo(vector<int> adj[], int n)
{
    int indegree[n] = {0};
    queue<int> q;
    vector<int> topo;

    for (int i = 0; i < n; i++)
    {
        for (auto adjNode : adj[i])
        {
            indegree[adjNode]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto adjNode : adj[node])
        {
            indegree[adjNode]--;
            if (indegree[adjNode] == 0)
            {
                q.push(adjNode);
            }
        }
    }

    return topo;
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
        // adj[v].push_back(u);
    }

    int vis[n];
    stack<int> sorted;
    vector<int> ans = topo(adj, n);

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
        sorted.pop();
    }

    return 0;
}