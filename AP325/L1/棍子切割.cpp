#include <bits/stdc++.h>
#define N 50010
using namespace std;
typedef long long LL;
LL p[N];

LL cut(int l, int r)
{
    if (r - l <= 1)
        return 0;
    int m = l;
    LL k = (p[r] + p[l]) / 2;
    for (int jump = (r - l) / 2; jump > 0; jump >>= 1)
    {
        while (m + jump < r && p[m + jump] < k)
        {
            m += jump;
        }
    }
    if (p[m] - p[l] < p[r] - p[m + 1])
    {
        m++;
    }
    return p[r] - p[l] + cut(l, m) + cut(m, r);
}
int main()
{
    memset(p, 0, N);
    int n, L=0;
    scanf("%d%d", &n, &L);
    p[0] = 0;
    p[n + 1] = L;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &p[i]);
    printf("%lld\n", cut(0, n + 1));
    return 0;
}