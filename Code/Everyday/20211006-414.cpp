class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        int size = nums.size();
        long a = LONG_MIN, b = LONG_MIN, c = LONG_MIN;
        for (int i = 0; i < size; ++i)
        {
            if (nums[i] > a)
            {
                c = b;
                b = a;
                a = nums[i];
            }
            else if (a > nums[i] && nums[i] > b)
            {
                c = b;
                b = nums[i];
            }
            else if (b > nums[i] && nums[i] > c)
            {
                c = nums[i];
            }
        }
        if (c != LONG_MIN)
            return c;
        else
            return a;
    }
};