// 一刷：2022 03 17 不会做，忘记 unordered_map 的建立和访问方式了

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> hashmap;
        int size = nums.size();
        for(int i = 0; i < size; ++i){
            if(hashmap.find(target - nums[i]) != hashmap.end())
                return {i, hashmap[target- nums[i]]};
            else
                hashmap[nums[i]] = i;

        }
        return {};
    }
};