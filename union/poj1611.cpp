#include <iostream>
using namespace std;

const int N = 30050;
int s[N];

void init_set(int n){
    for(int i=0;i<n;i++) s[i] = i;
}

int find_set(int x){
    if(x != s[x]) s[x]=find_set(s[x]);
    return s[x];
}

void merage(int a,int b){
    int roota = find_set(a);
    int rootb = find_set(b);
    if(roota != rootb) s[roota] = rootb;
}

int main(){
    int n,m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        init_set(n);
        while (m--)
        {
            int q, n1;
            cin >> q >> n1;
            for (int i = 1; i < q; i++)
            {
                int n;
                cin >> n;
                merage(n1, n);
                n1 = n;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (find_set(s[i]) == find_set(0))
                ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}