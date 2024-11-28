#include <iostream>
#include <vector>

#define inf 0x3f3f3f;
using namespace std;

int v,e;
int v1,v2,val;
int main(){
    cin >> v >> e;
    vector<vector<int> > grid(v + 1, vector<int>(v + 1, 10001));
    for(int i=0;i<e;i++){
        cin >> v1 >> v2 >> val;
        grid[v1][v2] = val;
        grid[v2][v1] = val;
    }

    vector<int> minDist(v+1, 10001);
    vector<bool> isInTree(v+1, false);

    vector<int> path(v+1,-1);

    for(int i=1;i<v;i++){
        int cur = -1;
        int minVal = inf;
        for(int j=1;j<=v;j++){
            if(!isInTree[j] && minDist[j] < minVal){
                minVal = minDist[j];
                cur = j;
            }
        }
        isInTree[cur] = true;
        for(int j=1;j<=v;j++){
            if(!isInTree[j] && grid[cur][j] < minDist[j]){
                minDist[j] = grid[cur][j];
                path[j] = cur;
            }
        }
    }

    int result = 0;
    for(int i=2;i<=v;i++){
        result += minDist[i];
    }

    cout << result << '\n';

    for(int i =1;i<=v;i++){
        cout << i << "->" << path[i] << endl;
    }
} 