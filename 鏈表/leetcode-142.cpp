#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Sloution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // 聲明快慢指針
        ListNode *slow = head, *fast = head;
        // 判斷是否為環
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        // 檢查是否為null
        if (fast == nullptr || fast->next == nullptr)
        {
            return NULL;
        }
        // 將slow或fast移回頭
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};