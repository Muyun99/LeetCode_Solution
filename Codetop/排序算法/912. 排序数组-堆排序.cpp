// 一刷：2022 03 16 不会做


// 堆是一个完全二叉树，可以用数组来存储
// 下标为i的节点的父坐标节点：(i-1) / 2
// 下标为i的节点的左孩子节点下标：i * 2 + 1
// 下标为i的节点的右孩子节点下标：i * 2 + 2
// 堆排序是不稳定的
class Solution {
public:
    // 维护最大堆
    // len 是数组长度
    // i 是需要维护的节点下标
    void maxHeapify(vector<int>& nums, int i, int heapsize){
        int largest = i;
        int leftson = i * 2 + 1;
        int rightson = i * 2 + 2;
        if(leftson < heapsize && nums[leftson] > nums[largest])
            largest = leftson;
        if(rightson < heapsize && nums[rightson] > nums[largest])
            largest = rightson;
        
        if(largest != i){
            swap(nums[largest], nums[i]);
            maxHeapify(nums, largest, heapsize);
        }
    }
    // 建堆的复杂度是 O(n)
    void buildHeap(vector<int>& nums, int heapsize){
        for(int i = heapsize / 2; i >= 0; --i){
            maxHeapify(nums, i, heapsize);
        }
    }

    void heapSort(vector<int>& nums){
        int heapsize = nums.size();
        buildHeap(nums, heapsize);

        for(int i = heapsize - 1; i > 0; --i){
            swap(nums[i], nums[0]);
            --heapsize;
            maxHeapify(nums, 0, heapsize);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};