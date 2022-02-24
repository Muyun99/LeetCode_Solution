/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/

// 解法1：使用哈希表，时间复杂度 O(n)，空间复杂度 O(n)
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(pHead == nullptr) return nullptr;
        unordered_map<RandomListNode*, RandomListNode*> hashmap;
        
        // 哨兵节点
        RandomListNode* dummy = new RandomListNode(0);
        RandomListNode* p = pHead;
        RandomListNode* newp = dummy;
        
        while(p){
            RandomListNode* newNode = new RandomListNode(p->label);
            hashmap[p] = newNode;
            
            newp->next = newNode;
            newp = newp->next;
            p = p->next;
        }
        newp->next = nullptr;
        
        // 遍历哈希表来构造 random 指针
        for(auto& [key, value] : hashmap){
            value->random = key->random == nullptr ? nullptr : hashmap[key->random];
        }
        return hashmap[pHead];
    }
};



// 解法2：链表拼接+拆分，时间复杂度 O(n)，空间复杂度 O(1)
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(pHead == nullptr)    return nullptr;
        RandomListNode* p = pHead;
        while(p){
            RandomListNode* newNode = new RandomListNode(p->label);
            newNode->next = p->next;
            p->next = newNode;
            
            p = newNode->next;
        }
        
        // 第二遍遍历，完善 random 节点
        // p 是 nextp 的前驱节点
        p = pHead;
        RandomListNode* newpHead = pHead->next;
        RandomListNode* newp = newpHead;
        
        while(p){
            newp->random = p->random==nullptr ? nullptr: p->random->next;
            if(p->next) 
                p = p->next->next;
            if(newp->next) 
                newp = newp->next->next;
        }
        
        // 恢复原先的连接关系
        p = pHead;
        newp = newpHead;
        while(p){
            p->next = p->next == nullptr ? nullptr : p->next->next;
            newp->next = newp->next == nullptr ? nullptr : newp->next->next;
            p = p->next;
            newp = newp->next;
        }
        return newpHead;
    }
};