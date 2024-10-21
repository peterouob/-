#include <bits/stdc++.h>
using namespace std;

int n, m, mx, my = 0;

void bfs(vector<vector<int>> &grid, int x, int y)
{
    grid[x][y] = 2;
    queue<pair<int, int>> q;
    q.push({x, y});

    vector<pair<int, int>> dic = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        for (auto [dx, dy] : dic)
        {
            int nr = r + dx;
            int nc = r + dy;
            if (nr < 0 || nr >= mx || nc < 0 || nc >= my || grid[nr][nc] == 0 || grid[nr][nc] == 2)
                continue;
            q.push({nr, nc});
        }
    }
}

int main()
{
    cin >> n >> m;
    mx = n;
    my = m;
    vector<vector<int>> grid = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 1)
            bfs(grid, i, 0);
        if (grid[i][m - 1] == 1)
            bfs(grid, i, m - 1);
    }

    for (int i = 0; i < m; i++)
    {
        if (grid[0][i] == 1)
            bfs(grid, 0, i);
        if (grid[n - 1][i] == 1)
            bfs(grid, n - 1, i);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                grid[i][j] = 0;
            if (grid[i][j] == 2)
                grid[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << i << j << endl;
        }
    }
}