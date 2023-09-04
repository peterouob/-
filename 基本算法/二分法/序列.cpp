#include <bits/stdc++.h>

using namespace std;
// [max,sum]
int m, n = 0;
int a[100001] = {0};
bool check(int x)
{
    int k = 0;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        if (a[i] + sum > x)
        {
            sum = 0;
            k++;
        }
        if (k > n - 1)
        {
            sum = 0;
            return false;
        }
        sum += a[i];
    }
    return true;
}
int bf(int max, int sum)
{
    int l = max;
    int r = sum;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}
int main()
{
    cin >> m >> n;
    int max = -1;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        if (a[i] > max)
        {
            max = a[i];
        }
        sum += a[i];
    }
    cout << bf(max, sum) << endl;
}