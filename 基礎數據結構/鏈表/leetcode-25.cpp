#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *a = head, *b = head;
        if (head == nullptr)
            return nullptr;
        for (int i = 0; i < k; i++)
        {
            if (b == nullptr)
                return head;
            b = b->next;
        }
        ListNode *newHead = reverse(a, b);
        head->next = reverseKGroup(b, k); // 將head接回後面的練表
        return newHead;
    }
    ListNode *reverse(ListNode *a, ListNode *b)
    {
        ListNode *pre = nullptr, *cur = a, *nxt = a;
        while (cur != b)
        {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};