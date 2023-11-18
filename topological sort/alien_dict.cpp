#include <iostream>
#include <vector>
#include <sstream>
#include <Queue>
#include <stack>
using namespace std;

vector<int> *makeGraph(string words[], int k, int n)
{
    vector<int> *adj = new vector<int>[k];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < words[i].size(); j++)
        {
            if (words[i][j] != words[i + 1][j])
            {
                // makeEdge(words[i][j], words[i+1][j]);
                adj[(int)(words[i][j] - 'a')].push_back((int)(words[i + 1][j] - 'a'));
                break;
            }
        }
    }

    return adj;
}

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
    int n, k;
    cin >> n;
    cin >> k;

    string words[n];

    for (int i = 0; i < n; i++)
    {
        getline(cin >> ws, words[i]);
    }

    vector<int> *adj = makeGraph(words, k, n);

    int vis[k] = {0};
    stack<int> sorted;
    for (int i = 0; i < k; i++)
    {
        if (!vis[i])
            topologicalSort(i, adj, vis, sorted);
    }

    string ans = "";
    for (int i = 0; i < n; i++)
    {
        ans += sorted.top() + 'a';
        cout << (char)(sorted.top() + 'a') << " ";
        sorted.pop();
    }

    return 0;
}