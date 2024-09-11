#include <bits/stdc++.h>

using namespace std;

int t, a, b, c;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> a;
        cin >> b;
        int r = INT_MAX;
        int c = a;
        while(c <= b){
            r = min(r,(c-a)+(b-c));
            c++;
        }
        cout << r << endl;
    }
}