#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int maxnum = nums[size - 1];

        vector<int> sum(maxnum + 1);
        vector<int> ans(maxnum + 1);
        for (int i = 0; i < size; ++i)
            sum[nums[i]] += nums[i];

        int sum_size = sum.size();
        if (sum_size == 1)
            return sum[0];
        if (sum_size == 2)
            return max(sum[0], sum[1]);

        ans[0] = sum[0];
        ans[1] = max(sum[0], sum[1]);
        for (int i = 2; i < sum_size; ++i)
            ans[i] = max(ans[i - 1], ans[i - 2] + sum[i]);

        return ans[sum_size - 1];
    }
};

int main()
{
    Solution sul;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    cout << sul.deleteAndEarn(nums);
    return 0;
}
