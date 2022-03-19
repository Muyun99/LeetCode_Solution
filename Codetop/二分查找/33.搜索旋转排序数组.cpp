// 一刷：2022 03 17 不会做
// 一刷：2022 03 18 会做

// 二分查找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while(left <= right){
            mid = (right - left) / 2 + left;
            if(nums[mid] == target) return mid;

            
            if(nums[mid] >= nums[left]){
                // 如果左侧有序
                if(nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else   
                    left = mid + 1;
            }
            else{
                // 如果左侧有序
                if(nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
