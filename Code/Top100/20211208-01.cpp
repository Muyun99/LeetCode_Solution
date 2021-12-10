// 解法1： 暴力法
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        int size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (nums[i] + nums[j] == target && i != j)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

// 解法2： 字典
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        map<int, int> hashtable;
        int size = nums.size();

        for (int i = 0; i < size; ++i)
        {
            if (hashtable.count(target - nums[i]) > 0)
            {
                ans.push_back(hashtable[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            hashtable[nums[i]] = i;
        }
        return ans;
    }
};