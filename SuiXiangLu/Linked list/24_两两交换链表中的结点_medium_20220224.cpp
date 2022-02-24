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
// 解法1：迭代，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* vhead = new ListNode(-1);

        // 哨兵结点
        vhead->next = head;
        ListNode* prepre = vhead;
        ListNode* pre = head;
        ListNode* cur = head->next;

        while(cur){
            
            ListNode* temp = cur->next;
            prepre->next = cur;
            cur->next = pre;
            pre->next = temp;
            
            if(pre->next != nullptr){
                prepre = prepre->next->next;
                cur = pre->next->next;
                pre = pre->next;
            }
            else
                break;
        }

        return vhead->next;
    }
};