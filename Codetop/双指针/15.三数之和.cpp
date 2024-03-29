// 一刷：2022 03 17 不会做
// 二刷：2022 03 18 不会做
// 三刷：2022 03 21 会做，小地方写错了
// 四刷：2022 03 22 会做
// 五刷：2022 03 22 大概会做，小地方写错了
// 六刷：2022 06 08 知道思路，未排序，去重写错了
// 七刷：2022 06 09 知道思路，大概会写
// 八刷：2022 07 31 知道思路，大概会写



// 双指针做法
// 时间复杂度：O(n^2)
// 空间复杂度：O(logN)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0) {
                return result;
            }
            // 错误去重方法，将会漏掉-1,-1,2 这种情况
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            // 正确去重方法
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                    // 当前元素不合适了，可以去重
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                    // 不合适，去重
                    while (left < right && nums[left] == nums[left - 1]) left++;
                } else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }

        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for(int i = 0; i < size; ++i){
            if(nums[i] > 0)
                return ans;

            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int left = i + 1;
            int right = size - 1;

            while(left < right){
                if(nums[i] + nums[left] + nums[right] < 0){
                    while(left < right && nums[left] == nums[left + 1])
                        ++left;
                    ++left;
                }
                else if(nums[i] + nums[left] + nums[right] > 0){
                    while(left < right && nums[right] == nums[right - 1])
                        --right;
                    --right;
                }
                else{
                    ans.push_back(vector<int> {nums[i], nums[left], nums[right]});
                    while(left < right && nums[right] == nums[right - 1])
                        --right;
                    while(left< right && nums[left] == nums[left + 1])
                        ++left;
                    --right;
                    ++left;
                }
            }
        }
        return ans;
    }
};