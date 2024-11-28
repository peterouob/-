#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Edge {
    int l;
    int r;
    int val;
    Edge(int left,int right,int value){
        l = left;
        r = right;
        val = value;
    }
};

const int n = 10001;

int s[n];

void init_set(){
    for(int i=0;i<n;i++) s[i] = i;
}

int find_set(int x){
    if(x != s[x]) s[x] = find_set(s[x]);
    return s[x];
}

void join(int a,int b){
    int roota = find_set(a);
    int rootb = find_set(b);
    if(roota != rootb) s[roota] = rootb;
}

int v,e;
int v1,v2,val;

int main(){
    cin >> v >> e;
    vector<Edge> edges;
    for(int i=0;i<e;i++){
        cin >> v1 >> v2 >> val;
        edges.push_back({ v1,v2,val});
    }

    sort(edges.begin(),edges.end(),[](const Edge &a,const Edge &b){
        return a.val < b.val;
    });

    init_set();

    int result = 0;
    for(Edge edge : edges) {
        int x = find_set(edge.l);
        int y = find_set(edge.r);

        if(x != y){
            result += edge.val;
            join(x,y);
        }
    }

    cout << result << '\n';
}