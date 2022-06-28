// 一刷：2022 03 24 不会做
// 二刷：2022 06 28 不会做

// 基于回溯的算法: 
// - 时间复杂度O(3^m + 4 ^n) m 是输入中对应三个字母的数字个数，n 是输入中对应四个字母的数字个数
// - 空间复杂度是新数组的空间 O(m + n)
class Solution {
public:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
    vector<string> ans;
    string ans_step;
    void backtracking(string& digits, int index){
        if(ans_step.size() == digits.size()){
            ans.push_back(ans_step);
            return ;
        }
        string letterstr = letterMap[digits[index] - '0'];
        for(int i = 0; i < letterstr.size(); ++i){
            ans_step.push_back(letterstr[i]);
            backtracking(digits, index + 1);
            ans_step.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return ans;
            
        backtracking(digits, 0);
        return ans;
    }
};