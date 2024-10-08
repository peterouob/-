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
    sort(vc.begin(), vc.end());
    // 1 2 2 7 9 -> 6
    ll sum = 0;
    for (ll v : vc)
    {
        if (v - sum > 1)
            break;
        sum += v;
    }
    cout << sum + 1;
}