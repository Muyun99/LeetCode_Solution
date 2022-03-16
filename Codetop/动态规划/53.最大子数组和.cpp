// 一刷：2022 03 16 不会做，不会优化空间


// 动态规划
// - 时间复杂度O(n)
// - 空间复杂度O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int pre = 0;
        int maxAns = nums[0];
        for(int i = 0; i < size; ++i){
            pre = max(pre + nums[i], nums[i]);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};