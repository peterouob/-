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
    ListNode *partition(ListNode *head, int x)
    {
        // step1.聲明兩個練表分別儲存超過和小於
        ListNode *dummy = new ListNode(0);
        ListNode *dummy2 = new ListNode(0);
        // 方便閱讀代碼
        ListNode *p1 = dummy, *p2 = dummy2;
        ListNode *p = head;

        while (p != NULL)
        {
            if (p->val >= x)
            {
                // 將大於練表建立起來
                p2->next = p;
                p2 = p2->next;
            }
            else
            {
                p1->next = p;
                p1 = p1->next;
            }
            // 斷開練表的next(指向nullptr)
            ListNode *tmp = p->next;
            p->next = nullptr;
            p = tmp;
        }
        // 連結2個練表
        p1->next = dummy2->next;
        return dummy->next;
    }
};