class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int size = prices.size();
        if (size == 1)
            return 0;

        int minval = prices[0];
        int maxval = prices[0];
        int ans = 0;
        for (int i = 1; i < size; ++i)
        {

            if (ans < prices[i] - minval)
            {
                maxval = prices[i];
                ans = prices[i] - minval;
            }
            else if (minval > prices[i])
            {
                minval = prices[i];
            }
        }
        return ans;
    }
};