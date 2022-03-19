// 一刷：2022 03 17 会做
// 二刷：2022 03 18 会做

// 贪心
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size == 0)   return 0;

        int minPrice = prices[0];
        int profit = 0;
        for(int i = 0;i < size; ++i){
            minPrice = min(minPrice, prices[i]);
            profit = max(profit, prices[i] - minPrice);
        }
        return profit;
    }
};


// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size == 0)   return 0;

        vector<vector<int>> dp(2, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for(int i = 1; i < size; ++i){
            dp[i % 2][0] = max(prices[i] + dp[(i - 1) % 2][1], dp[(i - 1) % 2][0]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], -prices[i]);
        }
        return dp[(size - 1) % 2][0];
    }
};