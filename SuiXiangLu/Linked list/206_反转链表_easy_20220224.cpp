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
// 解法1：遍历，时间复杂度：O(n)，空间复杂度：O(1)，
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* next = nullptr;
        head->next = nullptr;
        while(cur){
            next = cur->next;
            cur->next = pre;

            pre = cur;
            cur = next;
        }
        
        return pre;
    }
};

// 解法2：递归，时间复杂度：O(n)，其中 n 是链表的长度。需要对链表的每个节点进行反转操作。空间复杂度：O(n)，其中 n 是链表的长度。空间复杂度主要取决于递归调用的栈空间，最多为 n 层。

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
};