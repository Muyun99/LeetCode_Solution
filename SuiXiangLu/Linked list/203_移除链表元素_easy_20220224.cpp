// 解法1：遍历，时间复杂度O(n)，空间复杂度O(1)
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return nullptr;
        ListNode* vhead = new ListNode(-1);
        vhead->next = head;

        ListNode* pre = vhead;
        ListNode* cur = head;

        while(cur){
            if(cur->val == val){
                cur = cur->next;
                pre->next = cur;
            }
            else{
                
                pre = pre->next;
                cur = cur->next;
            }
        }
        return vhead->next;
    }
};

// 解法2：递归
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return nullptr;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};