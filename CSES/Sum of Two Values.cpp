#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<pair<int, int>> vc;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        vc.push_back({x, i + 1});
    }
    int l = 0;
    int r = n - 1;
    sort(vc.begin(),vc.end());
    while (l < r)
    {
        if (vc[l].first + vc[r].first > m)
            r--;
        else if (vc[l].first + vc[r].first < m)
        {
            l++;
        }
        else if (vc[l].first + vc[r].first == m)
        {
            cout << vc[l].second << " " << vc[r].second;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}