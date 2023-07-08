#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;getchar();
    while(n --){
        stack<char> st;
        while(true){
            char ch = getchar();
            if(ch == '\n' || ch == ' ' || ch == EOF){
                while(!st.empty()) {cout << st.top();st.pop();}
                if(ch == '\n' || ch == EOF) break;
                cout << " ";
            }
            else st.push(ch);
        }
    }
}