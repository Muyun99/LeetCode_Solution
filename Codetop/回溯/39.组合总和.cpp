// 一刷：2022 03 24 大概会做，但是没剪枝

// 基于回溯的算法: 
// - 时间复杂度O(n * 2^n) 这是一个比较松的上界，n 代表 candidates 数组中的数的数量
// - 空间复杂度是新数组的空间 O(target)
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> ans_step;
    void backtracking(vector<int>& candidates, int sum, int index, int targetSum){
        if(sum > targetSum || index == candidates.size())
            return;
        if(sum == targetSum){
            ans.push_back(ans_step);
            return;
        }

        for(int i = index; i < candidates.size(); ++i){
            ans_step.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, sum, i, targetSum);
            sum -= candidates[i];
            ans_step.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, 0, 0, target);
        return ans;
    }
};