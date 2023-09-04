#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5+10;

int a[N] = {0};
int main(){
    int n,c;cin >> n >> c;
    for(int i=1;i<=n;i++)cin >> a[i];
    sort(a+1,a+1+n);
    ll ans = 0;
    for(int i=1,j=1,k=1; i<=n;i++){
        while(j <= n && a[j]-a[i] < c)j++;
        while(k <= n && a[k]-a[i] <= c)k++;
        if(a[j]-a[i] == c && a[k-1]-a[i] == c && k-1 >=1) ans += k-j;
    }
    cout << ans << endl;
}