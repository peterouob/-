#include <bits/stdc++.h>

using namespace std;

int dp[10000005] = {0};

int main()
{
    memset(dp, 0, sizeof(dp));
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> dp[i];
        int start = 1, end = 1, p = 1;
        int maxsum = dp[1];
        for (int i = 2; i <= n; i++)
        {
            // 轉移方程-> dp[i]=max(dp[i-1]+a[i],a[i])
            if (dp[i - 1] + dp[i] >= dp[i])
                dp[i] = dp[i - 1] + dp[i];
            else
                p = i;
            if (dp[i] > maxsum)
            {
                maxsum = dp[i];
                start = p;
                end = i;
            }
        }
        cout << "Case :" << k << endl;
        cout << maxsum << " " << start << " " << end;
        if (k != t)
            cout << endl;
    }
}