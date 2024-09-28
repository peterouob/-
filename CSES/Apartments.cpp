#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 2e5;
int n, m, k, ans = 0;
int a[MAX_SIZE];
int b[MAX_SIZE];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + m);
    int i, j = 0;
    while (i < n && j < m)
    {
        if (abs(a[i] - b[j]) <= k)
        {
            i++;
            j++;
            ans++;
        }
        else
        {
            if (a[i] - b[j] > k)
            {
                j++;
            }
            else
            {
                i++;
            }
        }
    }
    cout << ans << '\n';
}