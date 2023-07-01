#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    node *l, *r;
    node(int val = 0, node *l = NULL, node *r = NULL) : val(val), l(l), r(r){};
};

const int N = 1e5 + 10;
int a[N], b[N],c[N] = {0};
int ct = 0;
void build(int l, int r, int &t, node *&root)
{
    int flag = -1;
    for (int i = l; i <= r; i++)
    {
        if (b[i] == a[t])
        {
            flag = i; // 獲得根在中序遍歷的位置
            break;
        }
    }
    if (flag == -1)
        return;
    root = new node(b[flag]);t++;
    if(flag > l) build(l,flag-1,t,root->l);
    if(flag < r) build(flag+1,r,t,root->r);
}

void dfs(node* root){
    if(root){
        dfs(root->l);
        dfs(root->r);
        c[ct++] = root->val;
    }
}

int main()
{
    int n;
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        node *root;
        int t = 1;
        build(1, n, t, root);
        dfs(root);
        for(int i=0;i<ct;i++){
            cout << c[i] << " ";
        }
    }
}