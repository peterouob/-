#include <bits/stdc++.h>
#define N 50010
using namespace std;
typedef long long LL;
LL p[N];

LL cut(int left, int right)
{
    if (right - left <= 1)
        return 0;
    int m = left;
    LL k = (p[right] + p[left]) / 2;
    for (int jump = (right - left) / 2; jump > 0; jump >>= 1)
    {
        while (m + jump < right && p[m + jump] < k)
        {
            m += jump;
        }
    }
    if (p[m] - p[left] < p[right] - p[m + 1])
    {
        m++;
    }
    return p[right] - p[left] + cut(left, m) + cut(m, right);
}
int main()
{
    memset(p, 0, N);
    int n, L = 0;
    scanf("%d%d", &n, &L);
    p[0] = 0;
    p[n + 1] = L;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &p[i]);
    printf("%lld\n", cut(0, n + 1));
    return 0;
}