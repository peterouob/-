#include <iostream>
using namespace std;

const int N = 1050;
int s[N];

void init_set(){
    for(int i=1;i<=N;i++) s[i] = i;
}

int find_set(int x) {
    if(x != s[x]) s[x] = find_set(s[x]);
    return s[x];
}

void merge_set(int x,int y){
    x=find_set(x);y=find_set(y);
    if(x!=y)s[x]=s[y];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,m,n,x,y;
    cin >> t;
    while(t--){
        cin >> n >> m;
        init_set();
        for(int i=1;i<=m;i++){
            cin >> x >> y;
            merge_set(x,y);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(s[i]==i)ans++;
        }
        cout << ans << '\n';
    }
}