#include <bits/stdc++.h>
using namespace std;

int n, x = 0;
int ans = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    vector<int> vc(n, 0);
    for(int &v : vc) cin >> v;
    sort(vc.begin(),vc.end());
    int l = 0;
    int r = vc.size()-1;
    while(l <= r){
        if(vc[l] + vc[r] > x){
            r--;
        }else{
            l++;
            r--;
        }
        ans++;
    }
    cout << ans << endl;
}