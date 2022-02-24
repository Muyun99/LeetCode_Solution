// 解法1：哈希表，时间复杂度：O(n)；空间复杂度：O(n)
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        unordered_set<ListNode*> st;
        while(pHead){
            if(st.find(pHead) == st.end()){
                st.insert(pHead);
                pHead = pHead->next;
            }
            else
                return pHead;
        }
        return nullptr;
    }
};

// 解法2：数学关系推导，时间复杂度O(n)，空间复杂度O(1)
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        
        ListNode* p1 = pHead;
        ListNode* p2 = pHead;
        
        while(p1 && p2){
            p1 = p1->next;
            if(p2->next == NULL)
                return p2->next;
            p2 = p2->next->next;
            
            if(p1 == p2){
                ListNode* p3 = pHead;
                while(p1 != p3){
                    p1 = p1->next;
                    p3 = p3->next;
                }
                return p1;
            }
            
            
        }
        return nullptr;
        
    }
};