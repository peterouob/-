#include <iostream>
using namespace std;

const int N = 10;

char g[N][N];
bool cols[N];
int n=0,k=0;
int ans;

void dfs(int col,int num){
    if(col == n){
        if(num == k) ans ++;
        return;
    }
    for(int i=0;i<n;i++){
        if(!cols[i] && g[col][i] == '#'){
            cols[i] = true;
            dfs(col+1,num+1);
            cols[i] = false;
        }
    }
    dfs(col+1,num);
}

int main() {
    while (cin >> n >> k)
    {
        if(n == -1 && k == -1) break;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> g[i][j];
            }
        }
        ans = 0;
        dfs(0,0);
        cout << ans << '\n';
    }
}
