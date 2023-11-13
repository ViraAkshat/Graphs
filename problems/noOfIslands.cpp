#include <iostream>
#include <vector>
#include <sstream>
#include <Queue>
using namespace std;

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> earth)
{
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int nrow = r + i;
                int ncol = c + j;

                if (nrow >= 0 && nrow < earth.size() && ncol >= 0 && ncol < earth[0].size() && earth[nrow][ncol] == 1 && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
}

int islands(vector<vector<int>> earth, int n, int m)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int count = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (!vis[row][col] && earth[row][col] == 1)
            {
                count++;
                bfs(row, col, vis, earth);
            }
        }
    }

    return count;
}

int main()
{
    int n, m;
    string line;
    getline(cin, line);
    stringstream words(line);
    words >> n;
    words >> m;
    vector<vector<int>> earth;

    for (int i = 0; i < n; i++)
    {
        string row;
        getline(cin, row);
        stringstream pts(row);
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int data;
            pts >> data;
            temp.push_back(data);
        }

        earth.push_back(temp);
    }

    cout << islands(earth, n, m);
}