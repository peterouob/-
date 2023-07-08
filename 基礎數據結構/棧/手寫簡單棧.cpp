#include <bits/stdc++.h>

const int N = 1e5+10;

struct st{
    char s[N];
    int t=0;
    void push(char ch){s[++t] = ch;}
    char pop(){return s[t];}
    bool empty(){return t==0?true:false;}
}Stack;