/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        int sum = 0;
        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        int l1val, l2val;
        while (l1 != nullptr || l2 != nullptr)
        {
            l1val = l1 ? l1->val : 0;
            l2val = l2 ? l2->val : 0;

            sum = l1val + l2val + carry;
            carry = sum / 10;
            if (head == nullptr)
            {
                head = new ListNode(sum % 10);
                tail = head;
            }
            else
            {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (carry != 0)
            tail->next = new ListNode(carry);

        return head;
    }
};