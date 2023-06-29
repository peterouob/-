#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int a[N] = {0};
deque<int> dq;

int main()
{
    memset(a, 0, sizeof(a));
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        while (!dq.empty() && a[dq.back()] > a[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= m)
        {
            // 窗口[i-m,i]
            while (!dq.empty() && dq.front() <= i - m)
                dq.pop_front();
            printf("%d", a[dq.front()]);
        }
    }

    printf("\n");
    while (!dq.empty())
        dq.pop_back();
    for (int i = 1; i <= n; i++)
    {
        while (!dq.empty() && a[dq.back()] < a[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= m)
        {
            while (!dq.empty() && dq.front() <= i - m)
                dq.pop_front();
            printf("%d", a[dq.front()]);
        }
    }
    printf("\n");
}

/*
當 dq 不為空且 a[dq.back()] 大於 a[i] 時，持續從 dq 的後面彈出元素，直到 dq 為空或者 a[dq.back()] 小於等於 a[i]。這樣可以保證 dq 中的元素是遞減的。

將 i 插入到 dq 的後面。

如果 i 大於等於 m，則需要計算並輸出當前窗口的最大值。首先，從 dq 的前面彈出元素，直到 dq 為空或者彈出的元素對應的索引小於等於 i - m。這樣可以保證 dq 中只包含窗口內的元素。然後，輸出 a[dq.front()]，即窗口內的最大值。

完成處理窗口最大值後，程式碼使用 printf("\n"); 輸出一個換行符號，然後將 dq 清空。

接下來的迴圈用於處理窗口最小值，運行的方式和處理最大值的部分相同，只是在比較大小時將 < 換成了 >。這樣可以保證 dq 中的元素是遞增的。在計算窗口最小值時，同樣需要先將窗口外的元素從 dq 中彈出，然後輸出 a[dq.front()]。

最後，程式碼使用 printf("\n"); 輸出最後一個換行符號，表示處理結束。

總結起來，這段程式碼是使用雙端隊列來處理窗口內的最大值和最小值。它遍歷數組 a，並使用雙端隊列 dq 來記錄窗口內的元素，保持 dq 中的元素遞減（或遞增）的順序，以方便求解窗口的最大值（或最小值）。*/