#include <iostream>
#include <vector>
#include <sstream>
#include <Queue>
#include <stack>
using namespace std;

void topologicalSort(int src, vector<int> adj[], int vis[], stack<int> &sorted)
{
    vis[src] = 1;
    for (auto adjNode : adj[src])
    {
        if (!vis[adjNode])
            topologicalSort(adjNode, adj, vis, sorted);
    }

    sorted.push(src);
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
    for (int i = 0; i < n; i++)
    {
        topologicalSort(i, adj, vis, sorted);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(sorted.top());
        cout << sorted.top() << " ";
        sorted.pop();
    }

    return 0;
}