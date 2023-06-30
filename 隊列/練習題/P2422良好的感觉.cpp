#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
ll a[N], sum[N] = {0};
deque<ll> dq;

int main()
{
    int maxsum = -N;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    sum[++n] = 0;
    dq.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        while (!dq.empty() && a[i] < a[dq.back()])
        {
            ll tmp = a[dq.back()];
            dq.pop_back();
            ll mul = tmp * (sum[i - 1] - sum[dq.back()]);
            if (mul > maxsum)
            {
                maxsum = mul;
            }
        }
        dq.push_back(i);
    }
    cout << maxsum;
}
//[i,dq.fornt()]
/*
    这题的思路可以去看洛谷p2422，下面提供完全的stl解法。
    1.先把前缀和数组用前后两个零圈住(其实原本前后两边就是0了，但要把n++)；
    2.用单调队列来实现每一个arr[i]的范围，对于每一个arr[i]来说，
        在单独队列中，它的前一个就是它的左边界下标，
        之后进队列的第一个比它小的数就是它的右边界下标。
        可能有些不好想，可以对着样例来看：3 1 6 4 5 2，处理完后变成0 3 1 6 4 5 2 0
        首先0入队，接着1入队，这时的队列：{0，1}，a[0]就是a[1]的左边界
        接着i=2，因为a[2]=1 < a[1]=3,所以a[2]就是a[1]的右边界，
        这时可以直接计算以a[1]为最小的区间值的乘积了，拿它和mx比较就可以了
        

————————————————
版权声明：本文为CSDN博主「超级无敌猪猪侠」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/wkyhnyq/article/details/130886039
*/