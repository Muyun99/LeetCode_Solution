// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size == 0)   return 0;
        
        vector<vector<int>> dp (2, vector<int> (4, 0));

        
        dp[0][0] = 0; // 手上不拥有股票且不在冷却期
        dp[0][1] = -prices[0]; // 手上拥有股票
        dp[0][2] = 0; // 在当天卖出股票
        dp[0][3] = 0; // 在冷冻期

        for(int i = 1; i < size; ++i){
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][3]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][3]) - prices[i]);
            dp[i % 2][2] = dp[(i - 1) % 2][1] + prices[i];
            dp[i % 2][3] = dp[(i - 1) % 2][2];
        }
        return max(dp[(size - 1) % 2][0], max(dp[(size - 1) % 2][2], dp[(size - 1) % 2][3]));
    }
}; 