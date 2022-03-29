// 一刷：2022 03 22 不会做


// 用动态规划
// 时间复杂度 O(N)
// 空间复杂度 O(N)
class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.size();
        int ans = 0;
        vector<int> dp(size, 0);
        
        for(int i = 1; i < size; ++i){
            // 只有当前位置为右括号时才判断
            if(s[i] == ')'){
                // 如果 i-1 处是左括号，则 i 一定会和 i-1 配对，最小的长度为2
                // 除此之外，如果 i-2 处合法，还应该加上 i-2 处的长度
                if(s[i - 1] == '('){
                    if(i >= 2)
                        dp[i] = dp[i - 2] + 2;
                    else
                        dp[i] = 2;
                }
                // 如果 i-1 处是右括号，则找前一个未配对的位置 i-dp[i-1]-1 是否为左括号，如果是左括号就可以配对，最小长度为 2 + dp[i-1]
                // 如果 i-dp[i]-2 ，还应该加上该位置的长度
                else if(i - dp[i-1] > 0 && s[i - dp[i - 1] - 1] == '('){
                    if(i - dp[i-1] - 2 >= 0)
                        dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2;
                    else
                        dp[i] = dp[i-1] + 2;
                }

                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};

// 用栈
// 时间复杂度 O(N)
// 空间复杂度 O(N)



// 两次遍历
// 时间复杂度 O(N)
// 空间复杂度 O(1)

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0;
        int right = 0;
        int size = s.size();
        int ans = 0;

        for(int i = 0; i < size; ++i){
            if(s[i] == '(')
                left++;
            else
                right++;

            if(left < right){
                left = 0;
                right = 0;
            }
            else if(left == right)
                ans = max(ans, left * 2);
        }
        left = 0;
        right = 0;
        for(int i = size - 1; i >= 0; --i){
            if(s[i] == '(')
                left++;
            else
                right++;

            if(left > right){
                left = 0;
                right = 0;
            }
            else if(left == right)
                ans = max(ans, left * 2);
        }

        return ans;

    }
};