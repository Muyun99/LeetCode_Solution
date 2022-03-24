// 一刷：2022 03 19 不会做

// 模拟过程就可以，不过很难整...
// - 时间复杂度 O(n)，会在一个区间，每次停留会进行O(k)次翻转操作
// - 空间复杂度 O(1)



class Solution {
public:
    // 翻转一个子链表，并且返回新的头与尾
    ListNode* Reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;

        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;

        ListNode* pre = dummyNode;
        ListNode* end = dummyNode;

        while(end->next){
            for(int i = 0; i < k && end != nullptr; ++i){
                end = end->next;
            }
            if(end == nullptr)
                break;

            ListNode* start = pre->next;
            ListNode* next = end->next;
            end->next = nullptr;
            
            pre->next = Reverse(start);
            start->next = next;
            pre = start;
            end = pre;

            
        }
        return dummyNode->next;
    }
};
