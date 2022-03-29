// 一刷：2022 03 16 迭代会做、递归不会
// 二刷：2022 03 18 迭代会做、递归大概会做，没想好
// 三刷：2022 03 21 迭代会做、递归大概会做，没想好
// 四刷：2022 03 22 迭代会做、递归会做
// 五刷：2022 03 29 迭代会做、递归会做


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
