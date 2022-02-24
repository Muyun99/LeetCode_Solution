/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
                
        // pre 作为新的 head
        ListNode* pre = NULL;
        ListNode* now = pHead;
        ListNode* next = pHead->next;
        
        
        while(now){
            next = now->next;
            now->next = pre;
            
            pre = now;
            now = next;
            next = now->next;
        }
        return pre;
    }
};