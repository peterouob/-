#include <bits/stdc++.h>

using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;

int main(){
    int n;cin >> n;
    while(n--){
        int op;cin >> op;
        if(op == 1){int x;cin >> x;pq.push(x);}
        else if(op == 2){cout << pq.top();}
        else pq.pop();
    }
}