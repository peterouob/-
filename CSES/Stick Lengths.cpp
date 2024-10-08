#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<ll> vc(n);
    for (ll &v : vc)
        cin >> v;
    sort(vc.begin(), vc.end());
    ll ans = 0;
    for (ll v : vc)
    {
        ans += abs(v - vc[n / 2]);
    }
    cout << ans;
}