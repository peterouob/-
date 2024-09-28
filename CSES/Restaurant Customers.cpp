#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<pair<int, int>> times;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        times.push_back({a, 1});
        times.push_back({b, -1});
    }
    sort(times.begin(),times.end());
    int currMax = 0;
    int maxCustom = 0;
    for (const pair<int, int> &t : times)
    {
        currMax += t.second;
        maxCustom = max(maxCustom, currMax);
    }
    cout << maxCustom << endl;
}