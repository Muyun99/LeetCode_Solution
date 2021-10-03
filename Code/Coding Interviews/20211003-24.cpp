/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *pre = head;
        ListNode *now = head->next;
        head->next = NULL;
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