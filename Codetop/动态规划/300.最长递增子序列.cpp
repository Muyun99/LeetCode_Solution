// 一刷：2022 03 18 不会做
// 一刷：2022 03 21 不会做，不会递推公式
// 一刷：2022 03 22 会做，但是ans写在了内层循环

// 动态规划
// 时间复杂度：O(N^2)
// 空间复杂度：O(N)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, 1);
        int ans = 0;
        for(int i = 0; i < size; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};


// 动态规划 + 二分查找
// 时间复杂度：O(NlogN)
// 空间复杂度：O(N)
// 属实是难

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);   
             
        for(int i = 1; i < size; ++i){
            if(nums[i] > dp.back())
                dp.push_back(nums[i]);
            else{
                int left = 0;
                int right = dp.size();
                while(left <= right){
                    int mid = (left + right) / 2;
                    if(dp[mid] < nums[i])
                        left = mid + 1;
                    else   
                        right = mid - 1;
                }
                dp[left] = nums[i];
            }
        }
        return dp.size();

    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size < 2)    
            return size;

        vector<int> dp;
        dp.push_back(nums[0]);

        for(int i = 1; i < size; ++i){
            // 如果大于 dp.back()，则直接放到后面
            if(nums[i] > dp.back())
                dp.push_back(nums[i]);
            // 如果小于 dp.back()，则
            else{
                // lower_bound 用于查找数组从 begin 到 end 的第一个小于 num的数字，返回该数字的地址
                auto iter = lower_bound(dp.begin(), dp.end(), nums[i]);
                *iter = nums[i];
               
            }
        }
        return dp.size();
    }
};