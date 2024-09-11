#include <bits/stdc++.h>
using namespace std;

int n, m, result = 0;

void dfs(vector<vector<int>> &grid, int x, int y, int mx, int my)
{
    grid[x][y] = 0;
    result++;
    vector<pair<int, int>> dic = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };
    for (auto [dx, dy] : dic)
    {
        int nx = x + dx;
        int ny = y + dy;
        if (nx >= 0 && nx < mx && ny >= 0 && ny < my && grid[nx][ny] == 1)
        {
            dfs(grid, nx, ny, mx, my);
        }
    }
}

int main()
{
    cin >> n >> m;
    vector<vector<int>> grid = vector<vector<int>>(n, vector<int>(m, 0));
    vector<vector<bool>> visits = vector<vector<bool>>(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    // left -> right
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 1)
            dfs(grid, i, 0, n, m);
        if (grid[i][m - 1] == 1)
            dfs(grid, i, m - 1, n, m);
    }

    for (int i = 0; i < m; i++)
    {
        if (grid[0][i] == 1)
            dfs(grid, 0, i, n, m);
        if (grid[n - 1][i] == 1)
            dfs(grid, n - 1, i, n, m);
    }

    result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                dfs(grid, i, j, n, m);
            }
        }
    }
    cout << result << endl;
}