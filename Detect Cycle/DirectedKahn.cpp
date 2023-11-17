#include <iostream>
#include <vector>
#include <sstream>
#include <Queue>
using namespace std;

// cycle detection in directed graphs using kahn algorithm
bool detectCycle(int src, vector<int> adj[], int n)
{
    int indegree[n] = {0};
    queue<int> q;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
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
        count++;
        q.pop();

        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    if (count == n)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int n, m;
    string line;
    getline(cin, line);
    stringstream nums(line);
    nums >> n;
    nums >> m;

    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        string edge;
        getline(cin, edge);
        stringstream nodes(edge);
        nodes >> u;
        nodes >> v;
        adj[u].push_back(v);
    }

    int vis[n] = {0};
    bool isCycle = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (detectCycle(i, adj, n))
            {
                isCycle = true;
                break;
            }
        }
    }

    cout << isCycle;

    return 0;
}