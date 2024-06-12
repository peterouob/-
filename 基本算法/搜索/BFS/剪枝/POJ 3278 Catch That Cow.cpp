#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;
int n, k;
int dis[MAX_N + 1];
int now;

queue<int> q;
int main()
{
    while (cin >> n >> k)
    {
        memset(dis, 0x3f, sizeof(dis));
        q.push(n);
        dis[n] = 0;
        while (!q.empty())
        {
            now = q.front();
            q.pop();
            if (now + 1 <= MAX_N && dis[now] + 1 < dis[now + 1])
            {
                dis[now + 1] = dis[now] + 1;
                q.push(now + 1);
            }
            if (now - 1 >= 0 && dis[now] + 1 < dis[now - 1])
            {
                dis[now - 1] = dis[now] + 1;
                q.push(now - 1);
            }
            if (now * 2 <= MAX_N && dis[now] + 1 < dis[now * 2])
            {
                dis[now * 2] = dis[now] + 1;
                q.push(now * 2);
            }
        }
        cout << dis[k] << '\n';
    }
}