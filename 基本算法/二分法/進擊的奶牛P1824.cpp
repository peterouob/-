#include <bits/stdc++.h>

using namespace std;
int n, m = 0;
int a[1000001] = {0};
int check(int dis)
{
    int cnt = 1, place = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] - a[place] >= dis)
        {
            cnt++;
            place = i;
        }
    }
    if (cnt >= m)
        return true;
    else
        return false;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int l = 0, r = a[n - 1] - a[0];
    int ans = 0;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    cout << ans << endl;
}