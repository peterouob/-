#include <bits/stdc++.h>

using namespace std;

const int INF = 0x7fffffff;

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int maxsum = -INF;
        int start = 1, end = 1, p = 1;
        int N;
        int sum = 0;
        cin >> N;
        for (int j = 1; j <= N; j++)
        {
            int a;cin >> a;sum+=a;
            if(sum > maxsum) {maxsum = sum ; start = p; end = j;}
            if(sum  < 0){
                sum = 0;
                p = j+1;
            }
        }
        cout << "Case "<<i <<":" << endl;
        cout << maxsum << " " << start<<" "<< end;
        if(i != T)cout<<endl;
    }
}
