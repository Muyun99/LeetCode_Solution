// 一刷：2022 03 19 会做，未 delete 释放空间

// 双指针
// - 时间复杂度 O(n)
// - 空间复杂度 O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dommyNode = new ListNode(0);
        dommyNode->next = head;

        ListNode* pre = dommyNode;
        ListNode* cur = head;
        for(int i = 0; i < n; ++i)
            cur = cur->next;
        
        while(cur){
            cur = cur->next;
            pre = pre->next;
        }
        ListNode* node = pre->next;
        pre->next = pre->next->next;
        delete node;
        return dommyNode->next;
    }
};

// 递归
// - 时间复杂度 O(n)
// - 空间复杂度 O(1)
class Solution {
public:
    int cur = 0;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr)
            return nullptr;
            
        head->next = removeNthFromEnd(head->next, n);

        ++cur;
        if(n == cur)
            return head->next;
        
        return head;
    }
};