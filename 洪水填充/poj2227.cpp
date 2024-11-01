#include <iostream>
#include <queue>
#include <cstring>

#define ll long long
using namespace std;

const int N = 300 + 10;
int mp[N][N];
bool visits[N][N];
int dict[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int n,m;

struct nodes {
    int _x;int _y;int _h;
    friend bool operator < (nodes a,nodes b){
        return  a._h > b._h;
    }
};

priority_queue<nodes> pq;

void init(){
    while(!pq.empty()) pq.pop();
    nodes node;
    memset(visits,false,sizeof(visits));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // 從4周往內
            if(i == 0 || j == 0 || i == n-1 || j == m-1){
                visits[i][j] = true;
                node._x = i;
                node._y = j;
                node._h = mp[i][j];
                pq.push(node);
            }
        }
    }
}

void bfs(){
    init();
    nodes node_;
    ll a=0;
    while(!pq.empty()){
        nodes node = pq.top();
        pq.pop();
        for(int i=0;i<4;i++){
            int nx = node._x + dict[i][0];
            int ny = node._y + dict[i][1];
            if(0 <= nx && nx < n && 0 <= ny&& ny < m && !visits[nx][ny]){
                visits[nx][ny] = true;
                node_._x = nx;
                node_._y = ny;
                node_._h = mp[nx][ny];
                if(node_._h < node._h) {
                    a += (node._h - node_._h);
                    node_._h = node._h;
                }
                pq.push(node_); 
            }
        }
    }

    cout << a << endl;
}


int main(){
    while(cin >> m >> n){
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin >> mp[i][j];
        bfs();
    }
}