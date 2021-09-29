class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *now = head;
        ListNode *pre = nullptr;
        if (!head)
            return head;
        while (now->next != nullptr)
        {
            ListNode *next = now->next;
            now->next = pre;
            pre = now;
            now = next;
        }
        now->next = pre;
        return now;
    }
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *now = head;
        ListNode *pre = nullptr;
        if (!head)
            return head;
        while (now)
        {
            ListNode *next = now->next;
            now->next = pre;
            pre = now;
            now = next;
        }
        return pre;
    }
};