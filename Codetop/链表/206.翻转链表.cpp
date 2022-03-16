// 一刷：2022 03 16 迭代会做、递归不会


// 迭代法
// - 时间复杂度 O(n)
// - 空间复杂度 O(1)


// 递归法
// - 时间复杂度 O(n)
// - 空间复杂度 O(n)

// 迭代法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        while(cur != nullptr){
            next = cur->next;
            cur->next = pre;

            pre = cur;
            cur = next;
        }
        return pre;
    }
};

// 递归法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
