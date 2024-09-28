#include <bits/stdc++.h>
using namespace std;

multiset<int> tickets;
int n,m=0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int k =0;
    for(int i=0;i<n;i++){
        cin >> k;
        tickets.insert(k);
    }
    int t =0;
    for(int i=0;i<m;i++){
        cin >> t;
        auto it = tickets.upper_bound(t);
        if(it == tickets.begin()){
            cout << -1 << endl;
        }else{
            cout << *(--it) << endl;
            tickets.erase(it);
        }
    }
}