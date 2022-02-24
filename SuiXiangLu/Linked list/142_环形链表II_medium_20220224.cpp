// 解法1：遍历，数学关系求解，时间复杂度O(n)，空间复杂度O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr){
            slow = slow->next;
            if(fast->next == nullptr)
                return nullptr;
            else
                fast = fast->next->next;
            
            if(slow == fast){
                ListNode* ptr = head;
                while(ptr != fast){
                    ptr = ptr->next;
                    fast = fast->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};