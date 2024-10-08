#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n=0;
    cin >> n;
    vector<int> a(n + 1), idx(n + 1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        idx[a[i]] = i;
    }
    int c = 1;
    for(int i=1;i<=n;i++){
        if(idx[i] <= idx[i-1]){
            c++;
        }
    }
    cout << c;
}