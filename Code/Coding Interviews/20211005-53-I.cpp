// 不会做 抄题解
class Solution
{
public:
    int searchleft(vector<int> &nums, int l, int r, int target)
    {
        if (l > r)
            return -1;
        int m = r + (l - r) / 2;
        if (nums[m] == target)
        {
            if (m == 0 || nums[m - 1] != target)
                return m;
            else
                r = m - 1;
        }
        else if (nums[m] > target)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
        return searchleft(nums, l, r, target);
    }
    int searchright(vector<int> &nums, int l, int r, int target)
    {
        if (l > r)
            return -1;
        int m = r + (l - r) / 2;
        if (nums[m] == target)
        {
            if (m == nums.size() - 1 || nums[m + 1] != target)
                return m;
            else
                l = m + 1;
        }
        else if (nums[m] > target)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
        return searchright(nums, l, r, target);
    }
    int search(vector<int> &nums, int target)
    {
        if (!nums.size())
            return 0;
        int l = searchleft(nums, 0, nums.size() - 1, target);
        int r = searchright(nums, 0, nums.size() - 1, target);
        if (l > -1 && r > -1)
        {
            return r - l + 1;
        }
        return 0;
    }
};