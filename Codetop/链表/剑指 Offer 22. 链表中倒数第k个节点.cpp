// 双指针
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *slow = head;
        ListNode *fast = head;
        for(int i = 0; i < k; ++i)
            fast = fast->next;
        
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};