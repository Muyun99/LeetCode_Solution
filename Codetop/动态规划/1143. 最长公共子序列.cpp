// // 一刷：2022 03 16 会做，但是递推公式冗余了
// // 二刷：2022 03 19 大概会做，但是递推公式冗余了
// // 三刷：2022 03 22 大概会做，但是还得巩固

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size();
        int size2 = text2.size();
        
        vector<vector<int>> dp (size1 + 1, vector<int> (size2 + 1, 0));

        for(int i = 1; i <= size1; ++i)
            for(int j = 1; j <= size2; ++j){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        return dp[size1][size2];
    }
};