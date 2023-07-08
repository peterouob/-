#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int a[N];
deque<int> dq;

int main()
{
    memset(a, 0, sizeof(a));
    int n, k = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        while (!dq.empty() && a[dq.back()] < a[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k)
        {
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            cout << a[dq.front()] << endl;
        }
    }
}