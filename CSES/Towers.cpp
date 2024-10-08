#include <bits/stdc++.h>
#define ll long long 
using namespace std ;

int main(){
    int n = 0;
    int sz = 0;
    int tower = 0;
    cin >> n;
    multiset<int> ms;
    while(n--){
        cin >> sz;
        auto it = ms.upper_bound(sz);
        if(it != ms.end()){
            ms.erase(it);
            ms.insert(sz);
        }else{
            tower++;
            ms.insert(sz);
        }
    }
    cout << tower;
}