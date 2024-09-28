#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ;
    cin >> n;
    set<int> s;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        s.insert(num);
    }
    cout << s.size() << '\n';
}