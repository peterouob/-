#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 50005;

int s[N];
int d[N];
int ans;
void init_set(int n){
    for(int i=0;i<=n;i++){
        s[i]=i;
        d[i]=0;
    }
}

int find_set(int x){
    if(x != s[x]){
        int t = s[x];
        s[x] = find_set(s[x]);
        d[x] = (d[x]+d[t])%3;
    }
    return s[x];
}

void merage_set(int x,int y,int relation){
    int roota = find_set(x);
    int rootb = find_set(y);
    if(roota==rootb){
        if((relation-1)!=((d[x]-d[y]+3)%3))ans++;
    }else{
        s[roota]=rootb;
        d[roota]=(d[y]-d[x]+relation-1)%3;
    }
}

int main(){
    ios::sync_with_stdio(0);
    int n,k;scanf("%d%d",&n,&k);
    init_set(n);
    ans=0;
    while(k--){
        int relation,x,y;scanf("%d%d%d",&relation,&x,&y);
        if(x>n || y>n || (relation==2&&x==y))ans++;
        else merage_set(x,y,relation);
    }
    printf("%d",ans);
    return 0;
}