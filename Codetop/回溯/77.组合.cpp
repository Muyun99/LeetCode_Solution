// 一刷：2022 06 28 不太熟练

// 剪枝前
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(int n, int k, int startIndex){
        if(path.size() == k){
            ans.push_back(path);
            return;
        }
        for(int i = startIndex; i <= n; ++i){
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return ans;
    }
};

// 剪枝后
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(int n, int k, int startIndex){
        if(path.size() == k){
            ans.push_back(path);
            return;
        }
        for(int i = startIndex; i <= n - (k - path.size()) + 1; ++i){
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return ans;
    }
};