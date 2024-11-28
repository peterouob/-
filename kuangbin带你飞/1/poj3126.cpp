#include <iostream>
#include <vector>

#define inf 0x3f3f3f

using namespace std;
const int N = 10005;
vector<int> prim;
bool is_prim[N];

int visits[N];
int cnt[N];

void pr() {
    for(int i=2;i <= 10001;i++)
        is_prim[i] = true;
    for(int i=2;i<=10001;i++)
        if(is_prim[i])
            for(int j=i*2;j<=10001;j+=i)
                is_prim[j] = false;
}

void init(int a,int b){
    memset(visits, 0, sizeof(visits));
    for(int i=0;i<=N;i++) cnt[i] = inf;
    cnt[a] = 0;
}

int main(){
    cin.tie(0);
    
    int a,b;
    int n;
    pr();
    cin >> n;
    while(n--){
        cin >> a >> b;
    }
}
