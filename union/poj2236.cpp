#include <stdio.h>
#include <iostream>
using namespace std;

const int N = 1050;
int s[N];
int x[N];
int y[N];
bool m[N];
int r[N];

int find_set(int x){
    if(x != s[x]) s[x] = find_set(s[x]);
    return s[x];
}

void merage(int a,int b){
    int roota = find_set(a);
    int rootb = find_set(b);
    if(roota != rootb) s[roota] = rootb;
}

int dis(int a,int b){
    return (((x[a] - x[b]) * (x[a] - x[b]))+((y[a] - y[b]) * (y[a] - y[b])));
}

int main()
{
    int n, d;
    cin >> n >> d;
    for(int i=1;i<=n;i++){
        cin >> x[i-1] >> y[i-1];
        s[i] = i;
        m[i] = false;
    }
    char c;
    int p;
    int idx=0;
    while(cin >> c){
        if(c == 'O'){
            cin >> p;
            p--;
            r[idx++] = p;
            for(int i=0;i<idx;i++){
                if(dis(r[i],p) <= d*d) merage(r[i],p);
            }
        }else if(c =='S'){
            int l=0,r=0;
            cin >> l >> r;
            l--;r--;
            int rootl = find_set(l);
            int rootr = find_set(r);
            rootl == rootr ? cout << "SUCCESS" << '\n' : cout << "FAIL" << '\n';
        }
    }
}