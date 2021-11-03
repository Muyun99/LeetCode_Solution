class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 1)
            return nums[0];

        int ans = nums[0];
        int max_ans = ans;
        for (int i = 1; i < size; ++i)
        {
            ans = max(nums[i], nums[i] + ans);
            max_ans = max(max_ans, ans);
        }

        return max_ans;
    }
};