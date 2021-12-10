class Solution
{
public:
    int getleftborder(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int leftboarder = -2;
        while (left <= right)
        {
            int middle = left + ((right - left) / 2);
            if (nums[middle] >= target)
            {
                right = middle - 1;
                leftboarder = right;
            }
            else
                left = middle + 1;
        }
        return leftboarder;
    }
    int getrightborder(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int rightboarder = -2;
        while (left <= right)
        {
            int middle = left + ((right - left) / 2);
            if (nums[middle] <= target)
            {
                left = middle + 1;
                rightboarder = left;
            }
            else
                right = middle - 1;
        }
        return rightboarder;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int leftboarder = getleftborder(nums, target);
        int rightboarder = getrightborder(nums, target);
        if (leftboarder == -2 || rightboarder == -2)
            return {-1, -1};
        if (rightboarder - leftboarder > 1)
            return {leftboarder + 1, rightboarder - 1};
        return {-1, -1};
    }
};