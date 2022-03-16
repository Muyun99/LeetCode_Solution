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
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        return nums[size-k];
    }
};

// 基于堆排序
// 时间复杂度：O()
// 空间复杂度：O()