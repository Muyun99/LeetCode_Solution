// 一刷：2022 03 19 不会做，推不出公式，初始化有问题

// 根据题意，任意时刻，fast 指针走过的距离都为 \textit{slow}slow 指针的 22 倍。因此，我们有

// a+(n+1)b+nc=2(a+b)⟹a=c+(n−1)(b+c)

// 有了 a=c+(n-1)(b+c)  的等量关系，我们会发现：从相遇点到入环点的距离加上 n-1 圈的环长，恰好等于从链表头部到入环点的距离。

// 因此，当发现 slow 与 fast 相遇时，我们再额外使用一个指针 ptr。起始，它指向链表头部；随后，它和 slow 每次向后移动一个位置。最终，它们会在入环点相遇。

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr){
            slow = slow->next;
            if(fast->next == nullptr)
                return nullptr;
            fast = fast->next->next;
            
            if(slow == fast){
                ListNode* node = head;
                while(node != slow){
                    node = node->next;
                    slow = slow->next;
                }
                return node;
            }
        }
        return nullptr;
    }
};
