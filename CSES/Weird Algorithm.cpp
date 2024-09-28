#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int n;
    while(cin >> n){
        while (true)
        {
            cout << n << " ";
            if (n == 1)
                break;
            if (n % 2 == 1)
                n = n * 3 + 1;
            else
                n = n / 2;
        }
    }
    cout << '\n';
}