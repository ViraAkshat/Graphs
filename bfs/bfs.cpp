#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

void bfs(int n, vector<int> adj[])
{
    queue<int> children;  // queue to get the next immediate child
    int visited[n] = {0}; // keep track of visited nodes
    visited[0] = 1;
    children.push(0);
    vector<int> bfsTraversal; // add the traversal

    while (!children.empty())
    {
        int node = children.front(); // traverse the first node in queue
        children.pop();
        bfsTraversal.push_back(node);

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                children.push(it); // add adjacent node if not already there
            }
        }
    }

    for (int i = 0; i < bfsTraversal.size(); i++)
    {
        cout << bfsTraversal[i] << " ";
    }
}

int main()
{
    int n, m; // nodes and edges
    string line;
    getline(cin, line);
    stringstream words(line);

    words >> n;
    words >> m;

    // insert graph; adjacency list; O(2*Edges)
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        // cout << i << " ";

        int u, v;
        getline(cin >> ws, line);
        stringstream pts(line);
        pts >> u;
        pts >> v;
        // cout << "u: " << u << "v: " << v << endl;
        adj[u].push_back(v); // add a tuple in case of weighted graphs, (v, wt)
        adj[v].push_back(u); // skip in case of directed graph
        // cout << "end of " << i << endl;
    }

    // bfs on the graph
    bfs(n, adj);

    return 0;
}