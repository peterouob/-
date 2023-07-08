#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct myqueue
{
    int data[N];
    int head, rear;
    bool init()
    {
        head = rear = 0;
        return true;
    }
    int size() { return (rear - head); }
    bool empty()
    {
        if (size() == 0)
            return true;
    }
    bool push(int e)
    {
        if ((rear + 1) == head)
            return false;
        data[rear] = e;
        rear = (rear + 1);
        return true;
    }
    bool pop(int &e)
    {
        if (head == rear)
            return false;
        e = data[head];
        head = (head + 1);
        return true;
    }
} Q;

int main()
{
    int Hash[N] = {0};
    memset(Hash, 0, sizeof(Hash));
    int count = 0;
    int m, n;
    cin >> m >> n;
    while (n--)
    {
        int en;
        cin >> en;
        if (!Hash[en])
        {
            ++count;
            Q.push(en);
            Hash[en] = 1;
            while (Q.size() > m)
            {
                int tmp;
                Q.pop(tmp);
                Hash[tmp] = 0;
            }
        }
    }
    cout << count;
}