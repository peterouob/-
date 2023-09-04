#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N] = {0};

int m, n;
// 貪心劃分序列區間
//  用於尋找一個數字 x 的最佳切割點，使得在切割的過程中所得到的區間數量最小。

int check(int x)
{
    int s = 0;
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (s + a[i] <= x)
        {
            s += a[i];
        }
        else
        {
            s = a[i];
            cnt++;
        }
    }
    return cnt;
}

// l->max element, r->sum
int binsearch(int l, int r)
{
    int ans = 0;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid) <= m)
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}