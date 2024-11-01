#include <iostream>
#include <cstring>
using namespace std;

const int N = 500 + 10;

int n=0,m=0;
int current=0;

int mp[N][N];
bool visits[N][N];
pair<int,int> range[N];

int dict[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

void dfs(int x,int y,bool isReachable){
    visits[x][y] = true;
    if(x == n-1 && isReachable){
        range[current].first = min(range[current].first, y);
        range[current].second = max(range[current].second, y);
    }
    for(int i=0;i<4;i++){
        int nx = dict[i][0] + x;
        int ny = dict[i][1] + y;
        if(nx >= 0 && nx < n && ny >=0 && ny < m && !visits[nx][ny] && mp[x][y] > mp[nx][ny]){
            dfs(nx,ny,isReachable);
        }
    }
}


void init(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
        }
    }
}

int main(){
    while(cin >> n >> m ){
        init();
        for (int i = 0; i < m; i++)
            dfs(0, i, false);
        int un_reachable_cnt = 0;
        for (int i = 0; i < m; i++)
            if (!visits[n - 1][i])
                un_reachable_cnt++;
        if (un_reachable_cnt > 0)
        {
            cout << 0 << '\n'
                << un_reachable_cnt;
            return 0;
        }

        for(int i=0;i<m;i++){
            memset(visits,false,sizeof(visits));
            current = i;
            range[current].first = 501;
            if(n == 1)
                dfs(0,i,true);
            else if(mp[0][i] > mp[1][i])
                dfs(1,i,true);
        }

        int maxRightBound;
        current = -1;
        while(current < m - 1){
            maxRightBound = -1;
            for(int i=0;i<m;i++){
                if(range[i].first <= current+1 && range[i].second > maxRightBound)
                    maxRightBound = range[i].second;
            }
            un_reachable_cnt++;
            current = maxRightBound;
        }

        cout << 1 << '\n' << un_reachable_cnt;
        return 0;
    }
}