// 解法1：用 stack 先入后出的特性，时间复杂度 O(n)，空间复杂度 O(n)
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        if(k == 0)
            return nullptr;
         
        stack<ListNode*> s;
        ListNode* p = pHead;
        while(p){
            s.push(p);
            p = p->next;
        }
         
        while(!s.empty()){
            --k;
            if(k > 0)
                s.pop();
            else
                return s.top();
        }
        return nullptr;
    }
};

// 解法2：用快慢指针，时间复杂度 O(n)，空间复杂度 O(1)
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        if(pHead == nullptr || k == 0)    return nullptr;
        
        ListNode* slow = pHead;
        ListNode* fast = pHead;
        while(k && fast != nullptr){
            fast = fast->next;
            --k;
        }
        if(k)    return nullptr;
        while(fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};