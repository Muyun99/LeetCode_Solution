// 最长公共子序列（Leetcode 1143）

class Solution {
public:
    int minDistance(string word1, string word2) {
        int length_word1 = word1.length();
        int length_word2 = word2.length();
        vector<vector<int>> dp (length_word1 + 1, vector<int>(length_word2 + 1));
        for (int i = 1;i <= length_word1; ++i)
        {
            char c1 = word1[i-1];
            for (int j = 1;j <= length_word2; ++j)
            {
                char c2 = word2[j-1];
                if(c1 == c2)
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        int length_commonstr = dp[length_word1][length_word2];
    
        return length_word1 + length_word2 - 2 * length_commonstr;
    }
};

// 动态规划

class Solution {
public:
    int minDistance(string word1, string word2) {
        int length_word1 = word1.length();
        int length_word2 = word2.length();
        vector<vector<int>> dp (length_word1 + 1, vector<int>(length_word2 + 1));
        for (int i = 1;i <= length_word1; ++i)
            dp[i][0] = i;
        for (int j = 1;j <= length_word2; ++j)
            dp[0][j] = j;
        for (int i = 1;i <= length_word1; ++i)
        {
            char c1 = word1[i-1];
            for (int j = 1;j <= length_word2; ++j)
            {
                char c2 = word2[j-1];
                if(c1 == c2)
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1;
            }
        }
        return dp[length_word1][length_word2];
    }
};
