// 一刷：2022 03 24 不会做

// 基于回溯的算法: n 是数组 nums 的长度
// - 时间复杂度:
// - 空间复杂度:
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> ans_step;
    void backtracing(vector<int>& nums, int index){
        if(ans_step.size() > 1)
            ans.push_back(ans_step);
        
        unordered_set<int> uset; // 使用set对本层元素进行去重
        for(int i = index; i < nums.size(); ++i){
            // if(i > 0 && ans_step.size() != 0 && nums[i] < ans_step[0] && used[i - 1] == false)
            //     continue;

            if ((!ans_step.empty() && nums[i] < ans_step.back()) || uset.find(nums[i]) != uset.end()) {
                    continue;
            }
            uset.insert(nums[i]); // 记录这个元素在本层用过了，本层后面不能再用了
            ans_step.push_back(nums[i]);
            backtracing(nums, i + 1);
            ans_step.pop_back();
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracing(nums, 0);
        return ans;
    }
};