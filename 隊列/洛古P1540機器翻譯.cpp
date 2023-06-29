#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int Hash[N] = {0};
queue<int> Q;
int main()
{
    memset(Hash, 0, sizeof(Hash));
    int m, n;
    cin >> m >> n;
    int count = 0;
    while (n--)
    {
        int en;
        cin >> en;
        if (!Hash[en])
        {
            ++count;
            Q.push(en);
            Hash[en] = 1;
            while (Q.size() > m)
            {
                Hash[Q.front()] = 0;
                Q.pop();
            }
        }
    }
    cout << count;
}