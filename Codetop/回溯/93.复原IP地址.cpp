// 一刷：2022 03 24 不会做

// 基于回溯的算法: 
// SEG_COUNT = 4
// - 时间复杂度:O(3^SEG_COUNT *∣s∣)。
// - 空间复杂度:O(SEG_COUNT)
class Solution {
public:
    vector<string> ans;

    bool isValid(string& s, int start, int end){
        string substr = s.substr(start, end - start + 1);
        if(substr.size() > 3 || substr.size() == 0)
            return false;
        if(substr.size() != 1 && substr[0] == '0')
            return false;
        
        int num = 0;
        for(int i = 0; i< substr.size(); ++i){
            num = num * 10 + (substr[i] - '0');
            if(num > 255)
                return false;
        }
        return true;
    }
    void backtracking(string& s, int index, int pointNum){
        if(pointNum == 3){
            if(isValid(s, index, s.size() - 1) == true)
                ans.push_back(s);
            return ;
        }
        
        for(int i = index; i < s.size(); ++i){
            if(isValid(s, index, i) == true){
                s.insert(s.begin() + i + 1, '.');
                backtracking(s, i + 2, pointNum + 1);
                s.erase(s.begin() + i + 1);
            }
            else
                break;
        }
            
    }
    vector<string> restoreIpAddresses(string s) {
        int size = s.size();
        backtracking(s, 0, 0);
        return ans;
    }
};