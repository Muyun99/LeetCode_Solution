// 解法1：迭代
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* vhead = new ListNode(-1);
        ListNode* p = vhead;

        while(pHead1 && pHead2){
            if(pHead1->val <= pHead2->val){
                p->next = pHead1;
                pHead1 = pHead1->next;
            }
            else{
                p->next = pHead2;
                pHead2 = pHead2->next;
            }
            p = p->next;
        }
        p->next = pHead1 ? pHead1 : pHead2;
        return vhead->next;
    }
};

// 解法2：递归
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
    ListNode* vhead = new ListNode(-1);
    ListNode* p = vhead;
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if(!pHead1)    return pHead2;
        if(!pHead2)    return pHead1;
        
        if(pHead1->val < pHead2->val){
            pHead1->next = Merge(pHead1->next, pHead2);
            return pHead1;
        }
        else{
            pHead2->next = Merge(pHead1, pHead2->next);
            return pHead2;
        }
    }
};