#include <bits/stdc++.h>

using namespace std;
const int N = 10005;

struct Node
{
    char value;
    int lson, rson;
} tree[N];

int i = 1;

int newNode(char val)
{
    tree[i].value = val;
    tree[i].lson = 0;
    tree[i].rson = 0;
    return i++;
}

void Insert(int &father, int child, int l_r)
{
    if (l_r == 0)
        tree[father].lson = child;
    else
        tree[father].rson = child;
}

// dfn[i]表示i節點地1次被訪問的時間戳,dfn_order打印時間戳
int dfn[N] = {0};
int dfn_timer = 0;
void dfn_order(int father)
{
    if (father != 0)
    {
        dfn[father] = ++dfn_timer;
        printf("dfn[%c]=%d;", tree[father].value, dfn[father]);
        dfn_order(tree[father].lson);
        dfn_order(tree[father].rson);
    }
}

// DFS序
int visit_timer = 0;
void visit_order(int father)
{
    if (father != 0)
    {
        printf("visit[%c]=%d", tree[father].value, ++visit_timer);
        visit_order(tree[father].lson);
        visit_order(tree[father].rson);
        printf("visit[%c]=%d", tree[father].value, ++visit_timer);
    }
}

// 深度
int deep[N] = {0};
int deep_timer = 0;
void deep_order(int father)
{
    if (father != 0)
    {
        deep[father] = ++deep_timer;
        printf("deep[%c]=%d", tree[father].value, deep[father]);
        deep_order(tree[father].lson);
        deep_order(tree[father].rson);
        deep_timer--;
    }
}

// num[i]是以i為父親的子樹上的節點各數
int num[N] = {0};
int num_order(int father)
{
    if (father == 0)
        return 0;
    else
    {
        num[father] = num_order(tree[father].lson) + num_order(tree[father].rson) + 1;
        printf("num[%c]=%d", tree[father].value, num[father]);
        return num[father];
    }
}

void preorder(int father)
{
    if (father != 0)
    {
        cout << tree[father].value << " ";
        preorder(tree[father].lson);
        preorder(tree[father].rson);
    }
}

void inorder(int father)
{
    if (father != 0)
    {
        inorder(tree[father].lson);
        cout << tree[father].value << " ";
        inorder(tree[father].rson);
    }
}

void postorder(int father)
{
    if (father != 0)
    {
        postorder(tree[father].lson);
        postorder(tree[father].rson);
        cout << tree[father].value << " ";
    }
}

int buildTree()
{
    int A = newNode('A');
    int B = newNode('B');
    int C = newNode('C');
    int D = newNode('D');
    int E = newNode('E');
    int F = newNode('F');
    int G = newNode('G');
    int H = newNode('H');
    int I = newNode('I');

    Insert(E, B, 0);
    Insert(E, G, 1);
    Insert(B, A, 0);
    Insert(B, D, 1);
    Insert(G, F, 0);
    Insert(G, I, 1);
    Insert(D, C, 0);
    Insert(I, H, 1);

    int root = E;
    return root;
}

int main(void)
{
    int root = buildTree();
    cout << "dfn order: ";
    dfn_order(root);
    cout << endl;

    cout << "visit order: ";
    visit_order(root);
    cout << endl;

    cout << "deep order: ";
    deep_order(root);
    cout << endl;

    cout << "num order: ";
    num_order(root);
    cout << endl;

    cout << "preorder: ";
    preorder(root);
    cout << endl;

    cout << "inorder: ";
    inorder(root);
    cout << endl;

    cout << "postorder: ";
    postorder(root);
    cout << endl;
    return 0;
}