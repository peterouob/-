#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
int mp[N][N];
int vis[N][N];
int d[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}};
int flag;

void dfs(int x, int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y] = 1;
    while(q.size()){
        pair<int,int> tmp = q.front();
        q.pop();
        int tx = tmp.first;int ty = tmp.second;
        if(mp[tx][ty+1] == '#' && mp[tx][ty-1] == '#' &&
            mp[tx+1][ty] == '#' && mp[tx-1][ty] == '#'){
                flag = 1;
            }
        for(int i=0;i<4;i++){
            int nx = tx+d[i][0];int ny = ty+d[i][1];
            if(mp[nx][ny] == 0 && mp[nx][ny] == '#'){
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
}

int main(void)
{
}