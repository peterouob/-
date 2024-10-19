#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

struct Node {
    char value;
    int lson;
    int rson;
} tree[N]; // tree[0]不用表示空節點

int n = 1; // 記錄節點位置
int newNode(char val)
{
    tree[n].value = val;
    tree[n].lson = 0;
    tree[n].rson = 0;
    return n++;
}

void insert(int &father, int child, int l_r)
{
    l_r == 0 ? tree[father].lson = child : tree[father].rson = child;
}

int dfn[N] = {0};
int dfn_timer = 0;
void dfn_order(int father)
{
    if (father != 0)
    {
        dfn[father] = ++dfn_timer;
        printf("dfn[%c].value=%d ", tree[father].value, dfn[father]);
        dfn_order(tree[father].lson);
        dfn_order(tree[father].rson);
    }
}

int visit_time=0;
void visit_order(int father){
    if(father != 0){
        printf("visit[%c]=%d ",tree[father].value,++visit_time);
        visit_order(tree[father].lson);
        visit_order(tree[father].rson);
        printf("visit[%c]=%d ",tree[father].value,++visit_time);
    }
}

int deep[N] = {0};
int deep_timer = 0;
void deep_child(int father){
    if(father != 0){
        deep[father] = ++deep_timer;
        printf("deep[%c]=%d ",tree[father].value,deep[father]);
        deep_child(tree[father].lson);
        deep_child(tree[father].rson);
        --deep_timer;
    }
}

int num[N] = {0};
int num_node(int father){
    if(father == 0) return 0;
    else{
        num[father] = num_node(tree[father].lson)+ num_node(tree[father].rson) + 1;
        printf("num[%c]=%d ",tree[father].value,num[father]);
        return num[father];
    }
}

void pre_order(int father){
    if(father != 0) {
        cout << tree[father].value;
        pre_order(tree[father].lson);
        pre_order(tree[father].rson);
    }
}

void in_order(int father){
    if(father != 0) {
        in_order(tree[father].lson);
        cout << tree[father].value;
        in_order(tree[father].rson);
    }
}

void post_order(int father){
    if(father != 0) {
        post_order(tree[father].lson);
        post_order(tree[father].rson);
        cout << tree[father].value;
    }
}

int build_tree(){
    int A = newNode('A');int B = newNode('B');int C = newNode('C');
    int D = newNode('D');int E = newNode('E');int F = newNode('F');
    int G = newNode('G');int H = newNode('H');int I = newNode('I');

    insert(E,B,0);
    insert(E,G,1);
    insert(B,A,0);
    insert(B,D,1);
    insert(G,F,0);
    insert(G,I,1);
    insert(D,C,0);
    insert(I,H,0);
    int root = E;
    return root;
}

int main(){
    int root = build_tree();
    cout << "dfn order: "; dfn_order(root);cout << endl;
    cout << "visit order: ";  visit_order(root);cout << endl;
    cout << "deep child: " ; deep_child(root);cout << endl;
    cout << "num of tree: " <<  num_node(root) << endl;
    cout << "in order: " ; in_order(root);cout << endl;
    cout << "pre order: " ; pre_order(root);cout << endl;
    cout << "post order: ";post_order(root);cout << endl;
    return 0;
}