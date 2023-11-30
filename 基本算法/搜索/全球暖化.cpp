// 藍橋杯2018
#include "../../bits/stdc++.h"
using namespace std;

const int N = 10001;
char mp[N][N];
int vis[N][N] = {0};
int d[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {1, -1},
};
int flag;
int ans = 0;

void dfs(int x, int y)
{
    vis[x][y] = 1;
    if (mp[x][y + 1] == '#' && mp[x][y - 1] == '#' && mp[x + 1][y] == '#' && mp[x - 1][y] == '#')
        flag = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if (vis[nx][ny] == 0 && mp[nx][ny] == '#')
        {
            dfs(nx, ny);
        }
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> mp[i];
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (mp[i][j] == '#' && vis[i][j] == 0)
                {
                    flag = 0;
                    dfs(i, j);
                    if (!flag)
                        ans += 1;
                }
            }
        }
        cout << ans << endl;
    }
}