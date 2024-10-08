#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int> a, const pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    int n;
    cin >> n;
    vector<pair<int, int>> vc(n);
    for (int i = 0; i < n; i++)
        cin >> vc[i].first >> vc[i].second;
    sort(vc.begin(), vc.end(), cmp);

    int cur = 0;
    for (auto v : vc)
    {
        if (v.first >= cur)
        {
            ans++;
            cur = v.second;
        }
    }
    cout << ans;
}