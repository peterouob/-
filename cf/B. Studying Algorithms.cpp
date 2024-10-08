#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=0,m=0;cin >> n >> m;
    vector<int> vc(n,0);
    for(int &v : vc) cin >> v;
    sort(vc.begin(),vc.end());
    int i =0;
    int sum = 0;
    while(i < n && sum + vc[i] <= m){
        sum += vc[i];
        i++;
    }
    cout << i;
}