#include <bits/stdc++.h>

using namespace std;
using lit = list<int>::iterator;

const int N = 1e5 + 10;
int n, m;
list<int> node;
lit it[N];
int main()
{
    node.push_back(1);
    it[1] = node.begin();
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int k, p;
        cin >> k >> p;
        if (p == 0)
        {
            it[i] = node.insert(it[k], i);
        }
        else
        {
            auto pos = next(it[k]);
            it[i] = node.insert(pos, i);
        }
    }

    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        if (it[x] != node.end())
        {
            node.erase(it[x]);
            it[x] = node.end();
        }
    }
    for (auto n : node)
        cout << n;
}