#include <bits/stdc++.h>

using namespace std;

void find_sum(int a[],int n, int m){
    sort(a,a+n);
    int i =0,j=n-1;
    while(i < j){
        int sum = a[i]+a[j];
        if(sum > m)j--;
        if(sum < m)i++;
        if(sum == m)cout << a[i] << a[j] << endl;i++;
    }
}