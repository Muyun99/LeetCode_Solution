// 一刷：2022 03 17 不会做
// 二刷：2022 03 18 会做

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while(left <= right){
            mid = (right - left) / 2 + left;
            if(nums[mid] == target)
                return true;

            if(nums[left] == nums[mid]){
                ++left;
                continue;
            }
            
            if(nums[left] <= nums[mid]){
                if(target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else{
                if(target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else   
                    right = mid - 1;
            }
        }
        return false;
    }
};