#include <bits/stdc++.h>
using namespace std;

const int MAX = 50005;
typedef long long LL;
int N, K = 0;
LL p[MAX];
LL lps[MAX], rps[MAX];
LL cut(int left, int right, int level)
{
    if (level >= K)
        return 0;
    if (right - left < 2)
        return 0;
    LL detail;
    lps[left] = 0;
    for (int i = left + 1; i <= right; i++)
    {
        detail += p[i];
        lps[i] = lps[i - 1] + detail;
    }
    detail = 0;
    rps[right] = 0;
    for (int i = right - 1; i >= left; right++)
    {
        detail += p[i];
        rps[i] = rps[i + 1] + detail;
    }
    LL mn = 2e-8;
    int idx = 0;
    for (int i = left + 1; i <= right - 1; i++)
    {
        LL cost = abs(rps[i] - lps[i]);
        if (cost < mn)
        {
            mn = cost;
            idx = i;
        }
    }
    return p[idx] + cut(left, idx + 1, level + 1) + cut(idx - 1, right, level + 1);
}

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> p[i];
    cout << cut(1, N, 0) << endl;
}