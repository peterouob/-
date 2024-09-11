#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int M = 2e5 + 5;

int T, N;
ll a[M];

int c(int n)
{
    int tmp = 0;
    while (n)
    {
        tmp += n % 10;
        n /= 10;
    }
    return tmp;
}

int main()
{
    for (int i = 1; i <= 2e5; i++)
    {
        a[i] = a[i - 1] + c(i);
    }
    cin >> T;
    while (T--)
    {
        cin >> N;
        cout << a[N] << endl;
    }
}