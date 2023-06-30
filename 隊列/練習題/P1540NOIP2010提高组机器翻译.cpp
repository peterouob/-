#include <bits/stdc++.h>

using namespace std;

queue<int> q;
const int N = 1e5 + 10;
int Hash[N] = {0};
int ct = 0;

int main()
{
    int M, N = 0;
    cin >> M >> N;
    while (N--)
    {
        int en;
        cin >> en;
        if (!Hash[en])
        {
            ++ct;
            Hash[en] = 1;
            q.push(en);
            while (q.size() > M)
            {
                Hash[q.front()] = 0;
                q.pop();
            }
        }
    }
    cout << ct;
}