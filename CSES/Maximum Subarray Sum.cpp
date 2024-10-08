#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<ll> vc(n, 0);
    for (ll &v : vc)
        cin >> v;
    ll a1 = vc[0];
    ll total = 0;
    for (ll v : vc)
    {
        if (total < 0)
            total = 0;
        total += v;
        a1 = max(a1, total);
    }
    cout << a1;
}