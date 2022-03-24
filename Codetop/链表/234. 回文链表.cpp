// 一刷：2022 03 19 会做 但是不会优化

// 栈+挨个判断
// - 时间复杂度 O(2 * n)
// - 空间复杂度 O(n)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        
        ListNode* node = head;
        while(node){
            s.push(node->val);
            node = node->next;
        }
        
        node = head;
        while(node){
            if(node->val == s.top()){
                node = node->next;
                s.pop();
            }
            else
                return false;
        }
        return true;
    }
};

// 找中间节点+链表翻转
// - 时间复杂度 O(2 * n)
// - 空间复杂度 O(n)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow = slow->next;
        while(slow){
            if(head->val != slow->val)
                return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};