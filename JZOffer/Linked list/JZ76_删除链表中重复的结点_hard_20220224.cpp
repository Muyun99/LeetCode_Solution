// 解法1：用set，时间复杂度O(n)，空间复杂度O(1)到O(n)
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if(pHead == nullptr)    return pHead;
        set<int> s;
        ListNode* pre = pHead;
        ListNode* cur = pHead->next;
        while(cur){
            if(cur->val == pre->val)
                s.insert(cur->val);
            cur = cur->next;
            pre = pre->next;
        }
        
        ListNode* vhead = new ListNode(0);
        vhead->next = pHead;
        
        pre = vhead;
        cur = pHead;
        while(cur){
            if(s.count(cur->val) != 0){
                cur = cur->next;
                pre->next = cur;
                continue;
            }
            pre = pre->next;
            cur = cur->next;
        }
        
        return vhead->next;
    }
};


// 解法2：遍历一遍，如果有相同元素就跳过，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if(pHead == nullptr)    return nullptr;
        ListNode* vhead = new ListNode(-1);
        vhead->next = pHead;
        
        ListNode *pre = vhead;
        ListNode *cur = pHead;
        while(cur){
            if(cur->next && cur->val == cur->next->val){
                while(cur->next && cur->val == cur->next->val)
                    cur = cur->next;
                
                pre->next = cur->next;
                cur = cur->next;
            }
            else{
                pre = pre->next;
                cur = cur->next;
            }
            
        }
        
        return vhead->next;
    }
};