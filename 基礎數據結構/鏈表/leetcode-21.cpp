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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *p = dummy;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val > l2->val)
        {
            p->next = l2;
            l2 = l2->next;
        }
        else
        {
            p->next = l1;
            l1 = l1->next;
        }
        p = p->next;
    }

    if (l1 != NULL)
    {
        p->next = l1;
    }
    if (l2 != NULL)
    {
        p->next = l2;
    }
    return dummy->next;
};