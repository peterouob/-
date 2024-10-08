#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n=0;cin >> n;
    vector<pair<ll,ll> > vc(n);
    for(int i=0;i<n;i++) cin >> vc[i].first >> vc[i].second;
    sort(vc.begin(),vc.end());
    ll total = 0;
    ll ans = 0;
    for(auto v : vc){
        total += v.first;
        ans += v.second - total;
    }
    cout << ans;
}