// 一刷：2022 03 24 不会做

// 基于回溯的算法: 
// - 时间复杂度:
// - 空间复杂度:
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> ans_step;
    void backtracking(vector<int>& candidates, int sum, int index, int targetSum, vector<bool> used){
        if(sum == targetSum){
            ans.push_back(ans_step);
            return;
        }
        if(sum > targetSum || index == candidates.size())
            return;
        
        

        for(int i = index; i < candidates.size(); ++i){
            if(i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
                continue;

            ans_step.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;
            backtracking(candidates, sum, i + 1, targetSum, used);
            used[i] = false;
            sum -= candidates[i];
            ans_step.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, 0, 0, target, used);
        return ans;
    }
};