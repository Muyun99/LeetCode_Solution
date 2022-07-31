// 一刷：2022 03 17 不会做
// 二刷：2022 03 18 会做
// 三刷：2022 03 21 会做
// 四刷：2022 06 09 懂大概思路，细节出问题: while(left <= right)、if(nums[mid] >= nums[left])、nums[left] <= target
// 五刷：2022 06 16 很多地方出错误
// 六刷：2022 06 17 大概会做，if(nums[mid] >= nums[left]) 出错
// 七刷：2022 07 31 知道思路，但有不少地方出问题

// 二分查找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while(left <= right){
            mid = (right + left) / 2;
            if(nums[mid] == target) return mid;

            
            if(nums[mid] >= nums[left]){
                // 如果左侧有序
                if(nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else   
                    left = mid + 1;
            }
            else{
                // 如果右侧有序
                if(nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
