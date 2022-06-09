//  一刷：20200519 哈希表的建立和find()忘记了

// 暴力解法: 
// 时间复杂度O(n^2)
// 空间复杂度是新数组的空间 O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        for(int i = 0; i < size; ++i){
            for(int j = 0; j < size; ++j){
                if(nums[i] + nums[j] == target && i != j){
                    return {i, j};
                }
            }
        }
        return {0, 0};
    }
};

// 利用哈希表:
// 时间复杂度：O(n)
// 空间复杂度：N 是数组中元素的数量，主要为哈希表的开销

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