class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int size = nums.size();
        vector<int> ans1(size);
        vector<int> ans2(size);

        if (size == 1)
            return nums[0];
        if (size == 2)
            return max(nums[0], nums[1]);

        ans1[0] = nums[0];
        ans1[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size - 1; ++i)
        {
            if (ans1[i - 2] + nums[i] > ans1[i - 1])
                ans1[i] = ans1[i - 2] + nums[i];
            else
                ans1[i] = ans1[i - 1];
        }

        ans2[0] = 0;
        ans2[1] = nums[1];
        for (int i = 2; i < size; ++i)
        {
            if (ans2[i - 2] + nums[i] > ans2[i - 1])
                ans2[i] = ans2[i - 2] + nums[i];
            else
                ans2[i] = ans2[i - 1];
        }
        return max(ans1[size - 2], ans2[size - 1]);
    }
};