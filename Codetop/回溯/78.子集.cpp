// 一刷：2022 03 24 会做

// 基于回溯的算法: 
// - 时间复杂度:O(n * 2^n)，一共 2^n 个状态，每种状态需要 O(n) 的时间构造子集
// - 空间复杂度:O(n), ans_step 的数量
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> ans_step;
    void backtracking(vector<int>& nums, int index){
        ans.push_back(ans_step);
        for(int i = index; i < nums.size(); ++i){
            ans_step.push_back(nums[i]);
            backtracking(nums, i + 1);
            ans_step.pop_back();
            
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return ans;
    }
};