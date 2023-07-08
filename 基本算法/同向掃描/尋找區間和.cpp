#include <bits/stdc++.h>
using namespace std;

void findSum(int *a,int n,int s){
    int i=0,j=0;
    int sum = a[0];
    while(j < n){
        if(sum >= s){
            if(sum == s)cout << i << j << endl;
            sum -= a[i];
            i++;
            if(i > j){sum = a[i];j++;}
        }
        if(sum < s){
            j ++;
            sum += a[j];
        }
    }
}