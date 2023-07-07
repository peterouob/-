#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
int heap[N];
int len = 0;

void push(int val){
    heap[++len] = val;
    int i = len;
    while(i > 1 && heap[i] < heap[i/2]){
        swap(heap[i],heap[i/2]);
        i = i/2;
    }
}
void pop(){
    heap[1] = heap[len--];
    int i = 1;
    while(i*2 <= len) {
        int son = 2*i;
        if(son < len && heap[son+1] < heap[son]){
            son++;
            if(heap[son] < heap[i]){
                swap(heap[son],heap[i]);
                i = son;
            }
            else break;
        }
    }
}

int main(){
    int n ;scanf("%d",&n);
    while(n--){
        int op;scanf("%d",&op);
        if(op==1){int x;scanf("%d",&x);push(x);}
        else if(op == 2){printf("%d",heap[1]);}
        else pop();
    }
}
