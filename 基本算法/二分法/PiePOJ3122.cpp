#include <bits/stdc++.h>

using namespace std;
#define ll double
ll PI = acos(-1.0);
int n, m = 0;
ll a[10001] = {0};

bool check(ll mid)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (int)(a[i] / mid);
    }
    if (sum >= m)
        return true;
    else
        return false;
}

int main()
{
    int T = 0;
    cin >> T;
    while (T--)
    {
        ll maxx = 0;
        cin >> n >> m;
        m++;
        for (int i = 0; i < n; i++)
        {
            int r = 0;
            cin >> r;
            a[i] = r * r * PI;
            if (a[i] > maxx)
            {
                maxx = a[i];
            }
        }
        ll l = 0, right = maxx;
        for (int i = 0; i < 100; i++)
        {
            ll mid = l + (right - l) / 2;
            if (check(mid))
            {
                l = mid;
            }
            else
            {
                right = mid;
            }
        }
        printf("%.4f\n", l);
    }
}