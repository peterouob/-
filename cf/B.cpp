#include <bits/stdc++.h>
using namespace std;

int T;

map<int, char> mp;
stack<int> sc;
int main()
{
    cin >> T;
    while (T--)
    {
        mp.clear();
        int a;
        cin >> a;
        vector<int> vc(4);
        vc.clear();
        for (int i = 0; i < a; i++)
        {
            string s;
            cin >> s;
            for (int i = 0; i < 4; i++)
            {
                if (s[i] == '#')
                    sc.push(i + 1);
            }
        }
        while (!sc.empty())
        {
            int ans = sc.top();
            cout << ans << " ";
            sc.pop();
        }
        cout << endl;
    }
}