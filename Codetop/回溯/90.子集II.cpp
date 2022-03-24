// 一刷：2022 03 24 不会做

// 基于回溯的算法: n 是数组 nums 的长度
// - 时间复杂度:O(n * 2^n)，一共 2^n 个状态，每种状态需要 O(n) 的时间构造子集
// - 空间复杂度:O(n), ans_step 的数量
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> ans_step;
    
    void backtracking(vector<int>& nums, int index, vector<bool>& used){
        ans.push_back(ans_step);
        
        for(int i = index; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
            ans_step.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            used[i] = false;
            ans_step.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, 0, used);
        return ans;
    }
};