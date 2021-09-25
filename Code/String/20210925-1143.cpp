// 最长公共子序列
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int length_word1 = text1.length();
        int length_word2 = text2.length();
        vector<vector<int>> dp (length_word1 + 1, vector<int>(length_word2 + 1));
        for(int idx = 1; idx <= length_word1; ++idx)
        {
            char c1 = text1[idx-1];
            for(int jdx = 1; jdx <= length_word2; ++jdx)
            {
                char c2 = text2[jdx-1];
                if (c1 == c2)
                    dp[idx][jdx] = dp[idx - 1][jdx - 1] + 1;
                else
                    dp[idx][jdx] = max(dp[idx-1][jdx], dp[idx][jdx-1]);
            }
        }
        return dp[length_word1][length_word2];
    }
};