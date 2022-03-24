// 一刷：2022 03 19 不会做
// 二刷：2022 03 22 不会做

// 多路归并
// - 时间复杂度 O(k^2*N)
// - 空间复杂度 O(1)

class Solution {
public:
    ListNode* mergeLists(ListNode* list1, ListNode* list2){
        if(list1 == nullptr)    return list2;
        if(list2 == nullptr)    return list1;
        ListNode* dommyNode = new ListNode(0);
        ListNode* node = dommyNode;
        
        while(list1 && list2){
            if(list1->val < list2->val){
                node->next = list1;
                list1 = list1->next;
            }
            else{
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }
        node->next = list1 ? list1 : list2;
        return dommyNode->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        ListNode* ans = nullptr;
        for(int i = 0; i < size; ++i){
            ans = mergeLists(ans, lists[i]);
        }
        return ans;
    }
};

// 分治归并
// - 时间复杂度 O(k*N * logk)
// - 空间复杂度 O(1)
class Solution {
public:
    ListNode* mergetwoLists(ListNode* list1, ListNode* list2){
        if(list1 == nullptr)
            return list2;
        if(list2 == nullptr)
            return list1;
        ListNode* dommyNode = new ListNode(0);
        ListNode* node = dommyNode;
        while(list1 && list2){
            if(list1->val < list2->val){
                node->next = list1;
                list1 = list1->next;
            }
            else{
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }
        node->next = list1 ? list1 : list2;
        return dommyNode->next;
    }
    ListNode* merge(vector<ListNode*>& lists, int left, int right) {
        if(left == right)
            return lists[left];
        if(left > right)   
            return nullptr;
        int mid = (left + right) / 2;
        return mergetwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};

// 优先队列
// 时间复杂度：O(kn * logk)
// 空间复杂度：O(k)
class Solution {
public:
    struct Comp{
        bool operator() (ListNode* list1, ListNode* list2){
            return list1->val > list2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if(size == 0)   return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, Comp > q;

        for(int i = 0; i < size; ++i){
            if(lists[i] != nullptr)
                q.push(lists[i]);
        }

        ListNode* dommyNode = new ListNode(0);
        ListNode* cur = dommyNode;
        while(!q.empty()){
            cur->next = q.top();
            q.pop();
            cur = cur->next;
            if(cur->next != nullptr)
                q.push(cur->next);
        }
        return dommyNode->next;

    }
};
