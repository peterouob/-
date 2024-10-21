#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

int l, r, c;
char mp[31][31][31]; // z x y
int vis[31][31][31];
int s_x, s_y, s_z; // start
int e_x, e_y, e_z; // end

int d_x[6] = {0, 0, -1, 0, 1, 0};
int d_y[6] = {0, 0, 0, 1, 0, -1};
int d_z[6] = {1, -1, 0, 0, 0, 0};

class Point
{
public:
    Point(int x = 0, int y = 0, int z = 0) : _x(x), _y(y), _z(z) {};
    int _x, _y, _z;
};

int bfs()
{
    queue<Point> q;
    q.push(Point(s_x, s_y, s_z));
    vis[s_z][s_x][s_y] = 0;
    while (q.size())
    {
        Point p = q.front();
        q.pop();
        if (p._x == e_x && p._y == e_y && p._z == e_z)
            return vis[e_z][e_x][e_y];
        for (int i = 0; i < 6; i++)
        {
            int n_x = p._x + d_x[i];
            int n_y = p._y + d_y[i];
            int n_z = p._z + d_z[i];
            if (mp[n_z][n_x][n_y] != '#' && n_x >= 0 && n_x < r && n_y >= 0 && n_y < c && n_z >= 0 && n_z < l )
            {
                q.push(Point(n_x, n_y, n_z));
                vis[n_z][n_x][n_y] = vis[p._z][p._x][p._y] + 1;
                mp[n_z][n_x][n_y] = '#';
            }
        }
    }
    return -1;
}

int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> l >> r >> c)
    {
        if (l == 0 && r == 0 && c == 0)
            return 0;
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    cin >> mp[i][j][k];
                    if (mp[i][j][k] == 'S')
                    {
                        s_z = i;
                        s_x = j;
                        s_y = k;
                    }
                    else if (mp[i][j][k] == 'E')
                    {
                        e_z = i;
                        e_x = j;
                        e_y = k;
                    }
                }
            }
        }
        memset(vis,-1,sizeof(vis));
        int ans = bfs();
        ans == -1 ? printf("Trapped!\n") : printf("Escaped in %d minute(s).\n", ans);
    }
}