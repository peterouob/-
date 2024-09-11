#include "bits/stdc++.h"
using namespace std;
int T, N;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
        set<int> S;
        for (int i = 1; i <= N; i++)
        {
            map<char, int> mp;
            string s;
            cin >> s;
            for (auto x : s)
            {
                mp[x]++;
            }
            if (mp['1'])
                S.insert(mp['1']);
        }
        if (S.size() > 1)
            puts("TRIANGLE");
        else
            puts("SQUARE");
    }
}