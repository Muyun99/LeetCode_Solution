// 一刷：2022 03 19 大概会做 但是小细节上出问题了
// 建议阅读题解：https://leetcode-cn.com/problems/middle-of-the-linked-list/solution/kuai-man-zhi-zhen-zhu-yao-zai-yu-diao-shi-by-liwei/

// 快慢指针
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

