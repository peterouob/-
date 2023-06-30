#include <bits/stdc++.h>

using namespace std;

int a[10005] = {0};
deque<int> dq;
int maxsum = -1e5;
int main()
{
    int n, m, maxsum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        while (!dq.empty() && dq.front() < i - m)
            dq.pop_front();
        while (!dq.empty() && a[dq.back()] > a[i])
            dq.pop_back();
        dq.push_back(i);
        if (dq.empty())
        {
            maxsum = max(maxsum, a[i]);
        }
        else
        {
            maxsum = max(maxsum, a[i] - a[dq.front()]);
        }
    }
    cout << maxsum << endl;
}