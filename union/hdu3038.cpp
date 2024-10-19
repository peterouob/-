#include <iostream>
using namespace std;

const int N = 200010;

int s[N];
int d[N];

void init_set(int n){
    for(int i=0; i<= n;i++) {s[i]=i;d[i]=0;};
}

int find_set(int x){
    if(x != s[x]){
        int t = s[x];
        s[x] = find_set(s[x]);
        d[x] += d[t];
    }
    return s[x];
}

void mearge_set(int a,int b,int v,int&ans){
    int roota = find_set(a);
    int rootb = find_set(b);
    if(roota == rootb) {
        if(d[a]-d[b] != v) ans++; 
    }else{
        s[roota]=rootb;
        d[roota]=d[b]-d[a]+v;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF){
        init_set(n);
        int ans=0;
        while(m--){
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            a--;
            mearge_set(a,b,v,ans);
        }
        printf("%d\n",ans);
    }
}