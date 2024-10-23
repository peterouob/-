#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

const int N = 15;

vector<vector<int> > result;
vector<vector<int> > flip;

void convert(vector<vector<int> > &board, int n, int m, int x, int y) {
    int dict[5][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < 5; i++) {
        int dx = dict[i][0];
        int dy = dict[i][1];
        int nx = x + dx;
        int ny = y + dy;
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            board[nx][ny] ^= 1;
        }
    }
}

int ans = 1e9;

bool check_white(vector<vector<int> >&board,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] != 0) return false;
        }
    }
    return true;
}

void dfs(vector<vector<int> > &board, int n, int m, int pos, int flip_cnt) {
    if (pos == n * m) {
        if(check_white(board,n,m)){
            if(flip_cnt < ans){
                ans = flip_cnt;
                result = flip;
            }else if(flip_cnt == ans){
                result = min(flip,result);
            }
        }
        return;
    }

    int x = pos / n;
    int y = pos % n;

    dfs(board, n, m, pos + 1, flip_cnt);

    flip[x][y] = 1;
    convert(board, n, m, x, y);
    dfs(board, n, m, pos + 1, flip_cnt + 1);
    convert(board, n, m, x, y);
    flip[x][y] = 0;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n=0, m=0;
    while(scanf("%d%d",&n,&m) != EOF){
        vector<vector<int> > board(n, vector<int>(m));

        flip = vector<vector<int> >(n, vector<int>(m, 0));
        result = vector<vector<int> >(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j];
            }
        }

        dfs(board, n, m, 0, 0);

        if (ans == 1e9) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
        }
    }


    return 0;
}
