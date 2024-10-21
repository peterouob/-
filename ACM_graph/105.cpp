//
// Created by 林庭楷 on 2024/10/17.
//
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<list<int> >&grid,vector<bool>&visit,int n){
    if(visit[n]) return;
    visit[n] = true;
    list<int>keys = grid[n];
    for(int key : keys){
        dfs(grid,visit,key);
    }
}

int main(){
    int n,m;cin >> n>>m;
    int s,t;
    vector<list<int> > grid(n+1);
    while(m--){
        cin >> s >> t;
        grid[s].push_back(t);
    }
    vector<bool> visit(n+1);
    dfs(grid,visit,1);
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}