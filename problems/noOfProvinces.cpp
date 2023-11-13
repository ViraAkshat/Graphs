#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, ls);
        }
    }
}

void dfsOnGraph(int n, vector<int> adj[])
{
    int vis[n] = {0};
    int start = 0;
    vector<int> ls;

    dfs(start, adj, vis, ls);

    for (int i = 0; i < ls.size(); i++)
    {
        cout << ls[i] << " ";
    }
}

int main()
{
    int n, m;
    string line;
    getline(cin, line);
    stringstream words(line);
    words >> n;
    words >> m;
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        string lines;
        int u, v;
        getline(cin >> ws, lines);
        stringstream data(lines);
        data >> u;
        data >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int vis[n] = {0};
    int count = 0;
    vector<int> ls;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            count++;
            dfs(i, adj, vis, ls);
        }
    }

    cout << count;
}