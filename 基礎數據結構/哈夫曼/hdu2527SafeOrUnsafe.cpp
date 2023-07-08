#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin >> n;
    priority_queue<int,vector<int>,greater<int> > pq;
    while(n--){
        int num = 1;
        int sum = 0;
        int safeNum;cin >> safeNum;
        string s;cin >> s;
        sort(s.begin(), s.end());
        for(int i = 1;i<=s.length();i++){
            if(s[i] != s[i-1]){pq.push(num);num=1;}
            else num++;
        }
        while(pq.size() > 1){
            int a = pq.top();pq.pop();
            int b = pq.top();pq.pop();
            pq.push(a+b);
            sum += a+b;
        }
        pq.pop();
        if(sum > safeNum)cout<<"no"<<endl;
        else cout << "yes" << endl;
    }
}