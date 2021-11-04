class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int size = nums.size();
        unordered_map<int, int> hashtable;
        for (int i = 0; i < size; ++i)
        {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end())
            {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};