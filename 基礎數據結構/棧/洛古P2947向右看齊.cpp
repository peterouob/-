#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int h[N] = {0};
int ans[N] = {0};
stack<int> st;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() && h[st.top()] <= h[i])
            st.pop();
        if (st.empty()) ans[i] = 0;
        else ans[i] = st.top();
        st.push(i);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i];
}