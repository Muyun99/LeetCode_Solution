// 一刷：2022 03 19 迭代会做，但是写冗余了，递归不会做

// 迭代法
// - 时间复杂度 O(m + n)
// - 空间复杂度 O(1)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // if(list1 == nullptr)    return list2;
        // if(list2 == nullptr)    return list1;
        ListNode* dommyNode = new ListNode(0);
        ListNode* node = dommyNode;
        while(list1 && list2){
            if(list1->val < list2->val){
                node->next = list1;
                list1 =list1->next;
                node = node->next;
            }
            else{
                node->next = list2;
                list2 = list2->next;
                node = node->next;
            }
        }
        node->next = list1 ? list1 : list2;
        return dommyNode->next;
    }
};

// 递归
// - 时间复杂度 O(m + n)
// - 空间复杂度 O(m + n)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)    return list2;
        if(list2 == nullptr)    return list1;

        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};