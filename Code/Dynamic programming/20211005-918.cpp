// 不会做 抄题解
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int sum = nums[0];
        vector<int> dpmax(nums);
        vector<int> dpmin(nums);
        int size = nums.size();
        for (int i = 1; i < size; ++i)
        {
            dpmax[i] = max(nums[i], dpmax[i - 1] + nums[i]);
            dpmin[i] = min(nums[i], dpmin[i - 1] + nums[i]);
            sum += nums[i];
        }
        int maxv = *max_element(dpmax.begin(), dpmax.end());
        int minv = *min_element(dpmin.begin(), dpmin.end());
        return max(maxv, sum - minv == 0 ? maxv : sum - minv);
    }
};