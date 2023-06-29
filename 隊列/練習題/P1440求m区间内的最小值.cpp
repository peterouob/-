#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
int a[N] = {0};
deque<int> dq;
deque<int> deq;
bool flag = false;
int main()
{
    memset(a, 0, sizeof(a));
    int n, m = 0;
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        // 除後
        while (!dq.empty() && a[dq.back()] > a[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= m)
        {
            while (!dq.empty() && dq.front() <= i - m)
                dq.pop_front();
            deq.push_back(a[dq.front()]);
        }
    }
    if (m > 1)
    {
        deq.push_front(0);
    }
    for (auto d : deq)
    {
        cout << d;
    }
}
// 0 7 8 1 4 3 2