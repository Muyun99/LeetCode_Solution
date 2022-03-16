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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* vhead = new ListNode(-1);
        vhead->next = head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slowpre = vhead;
        
        while(n){
            fast = fast->next;
            --n;
        }
        
        while(fast){
            fast = fast->next;
            slow = slow->next;
            slowpre = slowpre->next;
        }
        slowpre->next = slow->next;
        return vhead->next;
    }
};

// 刷题记录
// 20220225 二刷 通过