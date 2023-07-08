#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
deque<int> dq;
int a[N] = {0};
int main()
{
    int n, m = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        a[i] = a[i] + a[i - 1];
    int maxsum = -N;
    dq.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        while (!dq.empty() && dq.front() < i - m)
            dq.pop_front();
        if (dq.empty())
            maxsum = max(maxsum, a[i]);
        else
            maxsum = max(maxsum, a[i] - a[dq.front()]);
        dq.push_back(i);
    }
    cout << maxsum;
}