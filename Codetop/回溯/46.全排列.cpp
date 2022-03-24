// 一刷：2022 03 22 不会做

// 基于回溯的算法: 
// - 时间复杂度O(n * n!) n 为序列的长度
// - 空间复杂度是新数组的空间 O(n)
class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, int first, int len){
        if(first == len){
            ans.emplace_back(nums);
            return;
        }
        for(int i = first; i < len; ++i){
            swap(nums[i], nums[first]);
            backtrack(ans, nums, first + 1, len);
            swap(nums[i], nums[first]);
        }
            
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(ans, nums, 0, nums.size());
        return ans;
    }
};