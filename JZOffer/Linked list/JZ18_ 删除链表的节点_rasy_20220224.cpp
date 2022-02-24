/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @param val int整型 
     * @return ListNode类
     */
    ListNode* deleteNode(ListNode* head, int val) {
        // write code here
        if(head == nullptr)    return nullptr;
        ListNode *vhead = new ListNode(-1);
        vhead->next = head;
        ListNode* pre = vhead;
        ListNode* cur = head;
        
        while(cur){
            if(cur->val == val){
                pre->next = cur->next;
                return vhead->next;
            }
            cur = cur->next;
            pre = pre->next;
        }
        return vhead->next;
    }
};