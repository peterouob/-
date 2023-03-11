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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 使用dummy當head避免不必要操作
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        // 因為新增dummy頭，所以遍歷n+1
        ListNode *x = findFromEnd(dummy, n + 1);
        // 刪除節點
        x->next = x->next->next;
        return dummy->next;
    }
    ListNode *findFromEnd(ListNode *head, int n)
    {
        ListNode *p1 = head;
        for (int i = 0; i < n; i++)
        {
            p1 = p1->next;
        }
        ListNode *p2 = head;
        while (p1 != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};