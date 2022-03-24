// 一刷：2022 03 19 会做，但是有冗余

// 迭代法
// - 时间复杂度 O(n)
// - 空间复杂度 O(1)

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* slow = head;

        // 注意初始化！！
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
