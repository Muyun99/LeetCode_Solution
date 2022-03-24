// 一刷：2022 03 23 不会做
// 一刷：2022 03 24 大概会做，回文的判断出错了

// 基于回溯的算法: 
// - 时间复杂度O(n * 2^n) n 为序列的长度
// - 空间复杂度是新数组的空间 O(n^2)
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> ans_step;
    vector<vector<bool>> status;

    void backtracking(string& s, int index){
        if(index == s.size()){
            ans.push_back(ans_step);
            return ;
        }

        for(int i = index; i < s.size(); ++i){
            if(status[index][i] == true){
                string substr = s.substr(index, i - index + 1);
                ans_step.push_back(substr);
                backtracking(s, i + 1);
                ans_step.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        int size = s.size();
        status.resize(size, vector<bool> (size, false));
        
        for(int i = 0; i < size; ++i)
            status[i][i] = true;
        
        for(int i = size - 1; i >= 0; --i){
            for(int j = i + 1; j < size; ++j){
                if(s[i] == s[j]){
                    if(j - i < 2)
                        status[i][j] = true;
                    else
                        status[i][j] = status[i + 1][j - 1];
                }
            }
        }
        backtracking(s, 0);
        return ans;
                
    }   
};