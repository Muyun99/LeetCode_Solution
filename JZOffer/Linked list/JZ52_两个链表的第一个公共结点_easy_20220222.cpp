// 解法1：用栈去实现
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        stack<ListNode*> s1;
        stack<ListNode*> s2;
        ListNode* ans = NULL;
        
        while(pHead1){
            s1.push(pHead1);
            pHead1 = pHead1->next;
        }
        while(pHead2){
            s2.push(pHead2);
            pHead2 = pHead2->next;
        }
        
        while(!s1.empty() && !s2.empty()){
            
            if(s1.top() == s2.top()){
                ans = s1.top();
                s1.pop();
                s2.pop();
            }
            else
                return ans;
        }
        return ans;
    }
};

// 解法2：遍历一遍
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        while(p1 != p2){
            if(p1 == NULL)
                p1 = pHead2;
            else
                p1 = p1->next;
            
            if(p2 == NULL)
                p2 = pHead1;
            else
                p2 = p2->next;
        }
        return p1;
    }
};


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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        while(p1 != p2){
            p1 = (p1 == NULL)? pHead2 : p1->next;
            p2 = (p2 == NULL)? pHead1 : p2->next;
        }
        return p1;
    }
};