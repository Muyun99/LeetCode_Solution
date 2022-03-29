// 一刷：2022 03 16 不会做
// 二刷：2022 03 18 会做，很顺畅
// 三刷：2022 03 21 基于堆排会做，较为顺畅，基于快排的卡了下
// 四刷：2022 03 29 基于堆排会做，较为顺畅，基于快排的不会做。。


// 一些注意的点
// 求中位数也是这个做法，k = nums.size() / 2
// 要求不修改数组，就用堆

// 基于快速排序的算法: 
// - 期望的时间复杂度O(n)，
// - 空间复杂度是递归中使用栈的空间 O(logn)

// 基于大顶堆排的算法: 
// - 时间复杂度O(nlogn)，建堆时间复杂度O(n), 删除的总代价是(k*logn)
// - 空间复杂度O(logn)

// 基于小顶堆排的算法: 
// 时间复杂度 O(nlogk)
// 空间复杂度 O(logn)





// 直接排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        return nums[size-k];
    }
};

// 基于快速排序
// 时间复杂度：O()
// 空间复杂度：O()
class Solution {
public:
    int partition(vector<int>& nums, int left, int right){

        int selectNum = rand() % (right - left + 1) + left;
        swap(nums[selectNum], nums[right]);
        int p = left;
        
        for(int i = left; i < right; ++i){
            if(nums[i] < nums[right]){
                swap(nums[i], nums[p]);
                ++p;
            }
        }
        swap(nums[right], nums[p]);
        return p;
    }

    
    int quickSelect(vector<int>& nums, int left, int right, int index){
        int p = partition(nums, left, right);
        if(p == index)
            return nums[p];
        else if(p < index)
            return quickSelect(nums, p + 1, right, index);
        else   
            return quickSelect(nums, left, p - 1, index);
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};


// 基于大顶堆排序
// 时间复杂度：O()
// 空间复杂度：O()

class Solution {
public:
    void maxHeapify(vector<int>& a, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l < heapSize && a[l] > a[largest]) {
            largest = l;
        } 
        if (r < heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify(a, largest, heapSize);
        }
    }

    void buildMaxHeap(vector<int>& a, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            maxHeapify(a, i, heapSize);
        } 
    }

    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heapSize;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
};


// 基于堆排序的方法
class Solution {
public:
    void maxHeapify(vector<int>& nums, int i, int heapsize){
        int large = i;
        int lson = i * 2 + 1;
        int rson = i * 2 + 2;

        if(lson < heapsize && nums[lson] > nums[large])
            large = lson;
        if(rson < heapsize && nums[rson] > nums[large])
            large = rson;
        
        if(large != i){
            swap(nums[large], nums[i]);
            maxHeapify(nums, large, heapsize);
        }
    
    }
    void buildHeadp(vector<int>& nums, int heapsize){
        for(int i = heapsize / 2; i >= 0; --i){
            maxHeapify(nums, i, heapsize);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int heapsize = nums.size();
        buildHeadp(nums, heapsize);    

        int i = heapsize;
        while(--k){
            swap(nums[--i], nums[0]);
            maxHeapify(nums, 0, --heapsize);
        }
        return nums[0];
        
    }
};


// 基于小顶堆的方法
class Solution {
public:
    void minHeapify(vector<int>& nums, int i, int heapsize){
        int min = i;
        int leftson = i * 2 + 1;
        int rightson = i * 2 + 2;
        
        if(leftson < heapsize && nums[leftson] < nums[min])
            min = leftson;
        if(rightson < heapsize && nums[rightson] < nums[min])
            min = rightson;

        if(i != min){
            swap(nums[i], nums[min]);
            minHeapify(nums, min, heapsize);
        }
    }

    void buildHeap(vector<int>& nums, int heapsize){
        for(int i = heapsize / 2; i >= 0; --i)
            minHeapify(nums, i, heapsize);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        buildHeap(nums, k);

        for(int i = k; i < size; ++i){
            if(nums[i] > nums[0]){
                swap(nums[i], nums[0]);
                minHeapify(nums, 0, k);
            }
        }
        return nums[0];
    }
};

// 小顶堆调库

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < k; ++i){
            pq.push(nums[i]);
        }
        for(int i = k; i < nums.size(); ++i){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};