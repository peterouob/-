/*
思路，把題目變成一個環
*/
#include <bits/stdc++.h>

using namespace std;

deque<int> dq;
const int N = 1e5 + 10;
int a[N], sum[N];
int ans = 0;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[n + i] = a[i]; // 變為環
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        while (!dq.empty() && dq.front() < i - n + 1)
            dq.pop_front();
        while (!dq.empty() && a[dq.back()] > sum[i])
            dq.pop_back();
        dq.push_back(i);
        if (!dq.empty() && a[dq.front()] - a[i - n] > 0)
            ++ans;
    }
    cout << ans;
}