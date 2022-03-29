// 一刷：2022 03 16 不会做，没分析出来递推公式
// 二刷：2022 03 18 大概会做，分析出来递推公式，但是 word[i-1] word2[j-1] 写错了
// 三刷：2022 03 21 大概会做，分析出来递推公式，但是 word[i-1] word2[j-1] 写错了，初始化 i <= size1 写成了 i < size


class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j] 表示 word1[0， i-1] 到 word2[0， j-1] 的最少操作次数
        // dp[0][j] = j, dp[i][0] = i
        // if(word[i] == word2[j])
                // 不操作
                // dp[i][j] = dp[i-1][j-1];
        // else
            // 增 
            // 删 dp[i][j-1] + 1 dp[i-1][j] + 1
            // 换 dp[i-1][j-1] + 1   
        int size1 = word1.size();
        int size2 = word2.size();
        vector<vector<int>> dp (size1 + 1, vector<int>(size2 + 1, 0));
        
        for(int i = 0; i <= size1; ++i)
            dp[i][0] = i;
        for(int i = 0; i <= size2; ++i)
            dp[0][i] = i;            
        
        for(int i = 1; i <= size1; ++i)
            for(int j = 1; j <= size2; ++j){
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        return dp[size1][size2];
    }
};