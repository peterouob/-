#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll val = 0;
ll ans = 0;
int main(){
    int n=0,m=0;cin >> n >> m;
    priority_queue<ll,vector<ll>,greater<ll> > pq;
    for(int i=0;i<m;i++){
        int v = 0;
        cin >> v;
        pq.push(v);
    }
    while(pq.size() > 1){
        ll t = pq.top();
        pq.pop();
        val = t + pq.top();
        pq.pop();
        pq.push(val);
        ans += val;
    }
    cout << ans;
}