//
// Created by 林庭楷 on 2024/10/17.
//
#include <bits/stdc++.h>
using namespace std;

int n = 0;
int m = 0;
int result = 0;

int main(){
    cin>>n>>m;
    vector<vector<int> >grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }

    int dict[4][2] =
            {
                    {0,1},
                    {0,-1},
                    {1,0},
                    {-1,0}
            };

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1){
                for(int k=0;k<4;k++){
                    int x = i + dict[k][0];
                    int y = j + dict[k][1];
                    if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) result++;
                }
            }
        }
    }
    cout << result << endl;
}