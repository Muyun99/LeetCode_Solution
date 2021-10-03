class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> ans(size + 1);
        if (size == 1)
            return nums[0];
        if (size == 2)
            return max(nums[0], nums[1]);

        ans[0] = nums[0];
        ans[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; ++i)
        {
            ans[i] = max(ans[i - 2] + nums[i], ans[i - 1]);
        }
        return max(ans[size - 1], ans[size - 2]);
    }
};
