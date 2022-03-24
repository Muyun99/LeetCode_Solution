// 一刷：2022 03 19 大概会做 但是小细节上出问题了

// 找中点，链表翻转，合并
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;

        ListNode* node1 = head;
        ListNode* node2 = reverseList(mid->next);
        mid->next = nullptr;

        ListNode* nextnode1 = nullptr;
        ListNode* nextnode2 = nullptr;

        while(node1 && node2){
            nextnode1 = node1->next;
            nextnode2 = node2->next;

            node1->next = node2;
            node1 = nextnode1;

            node2->next = node1;
            node2 = nextnode2;
        }
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};


// 个人风格的代码
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        if(head == nullptr)
            return;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;
        
        
        ListNode* node1 = head;
        ListNode* node2 = reverse(mid->next);
        mid->next = nullptr;
        

        ListNode* nextnode2 = nullptr;

        while(node1 && node2){
            nextnode2 = node2->next;
            node2->next = node1->next;
            node1->next = node2;
            node1 = node1->next->next;
            node2= nextnode2;

        }

    }
};