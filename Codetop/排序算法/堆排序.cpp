// 堆是一个完全二叉树，可以用数组来存储
// 下标为i的节点的父坐标节点：(i-1) / 2
// 下标为i的节点的左孩子节点下标：i * 2 + 1
// 下标为i的节点的右孩子节点下标：i * 2 + 2
// 堆排序是不稳定的

class Solution {
    // 维护最大堆
    // len 是数组长度
    // i 是需要维护的节点下标
    void maxHeapify(vector<int>& nums, int i, int len) {
        while((i << 1) + 1 <= len){
            int large = i;
            int lson = i * 2 + 1;
            int rson = i * 2 + 2;
            if (lson <= len && nums[lson] > nums[i]) {
                large = lson;
            } 
            if (rson <= len && nums[rson] > nums[large]) {
                large = rson;
            }

            if (large != i) {
                swap(nums[i], nums[large]);
                maxHeapify(nums, large, len);    
            } 
            else
                break;
        }
    }

    // 建堆的复杂度是 O(n)
    void buildMaxHeap(vector<int>& nums, int len) {
        
        for (int i = len / 2; i >= 0; --i) {
            maxHeapify(nums, i, len);
        }
    }
    void heapSort(vector<int>& nums) {
        int len = (int)nums.size() - 1;
        buildMaxHeap(nums, len);
        for (int i = len; i >= 1; --i) {
            swap(nums[i], nums[0]);
            len -= 1;
            maxHeapify(nums, 0, len);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};