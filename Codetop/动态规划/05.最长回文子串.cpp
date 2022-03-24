// 一刷：2022 03 22 不会做

// 基于动态规划的算法: 
// - 时间复杂度O(n^2)
// - 空间复杂度是新数组的空间 O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        vector<vector<bool>> dp(size, vector<bool> (size));
        
        for(int i = 0; i < size; ++i)
            dp[i][i] = true;
        
        int maxlen = 1;
        int begin = 0;
        
        for(int right = 1; right < size; ++right){
            for(int left = 0; left < right; ++left){
                if(s[left] != s[right])
                    dp[left][right] = false;
                else{
                    if(right - left < 3)
                        dp[left][right] = true;
                    else
                        dp[left][right] = dp[left + 1][right - 1];
                }

                if(dp[left][right] == true && right - left + 1 > maxlen){
                    maxlen = right - left + 1;
                    begin = left;
                }
            }
        }
        return s.substr(begin, maxlen);
    }
};

// 基于中心扩散
// - 时间复杂度O(n^2)
// - 空间复杂度是常数级别的 O(1)
class Solution {
public:
    pair<int, int> expandAroundCenter(const string& s, int left, int right){
        while(left >=0 && right < s.size() && s[left] == s[right]){
            --left;
            ++right;
        }
        return {left + 1, right - 1};

    }
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        int size = s.size();
        for(int i = 0; i < size; ++i){
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if(right1 - left1 > end - start){
                start = left1;
                end = right1;
            }
            if(right2 - left2 > end - start){
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};