class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int size = nums.size();
        // map<int, int>dict;
        for (int i = 0; i < size; ++i)
        {
            if (nums[i] != i)
                return i;
        }
        return size;
    }
};

// 二分查找不会做，抄题解
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size(), mid;
        int low = 0, high = n - 1;
        if (nums[0] != 0)
            return 0;
        while (low <= high)
        {
            mid = (low + high) >> 1;
            if (nums[mid] != mid && nums[mid - 1] == mid - 1)
                return mid;
            else if (nums[mid] > mid)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return high + 1;
    }
};