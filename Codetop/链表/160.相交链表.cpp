// 一刷：2022 03 19 不会做 

// 栈+挨个判断
// - 时间复杂度 O(m + n)
// - 空间复杂度 O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* nodeA = headA;
        ListNode* nodeB = headB;

        while(nodeA != nodeB){
            if(nodeA == nullptr)    
                nodeA = headB;
            else
                nodeA = nodeA->next;
                
            if(nodeB == nullptr)    
                nodeB = headA;
            else
                nodeB = nodeB->next;
        }
        return nodeA;
    }
};