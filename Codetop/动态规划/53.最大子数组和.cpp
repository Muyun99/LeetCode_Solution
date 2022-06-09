// 一刷：2022 03 16 不会做，不会优化空间
// 二刷：2022 03 18 不会做，递推公式没想出来....，刚学分治
// 三刷：2022 03 21 动态规划会做，线段树不会做
// 四刷：2022 03 22 动态规划会做，线段树大概会做，卡了 nums 的引用
// 五刷：2022 03 29 动态规划会做，线段树不会做
// 六刷：2022 03 29 动态规划不会做，没做线段树


// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int pre = 0;
        int maxAns = nums[0];
        for(int i = 0; i < size; ++i){
            pre = max(pre + nums[i], nums[i]);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};

// 分治：考察线段树
// 时间复杂度：O(n)
// 空间复杂度：O(logn)
class Solution {
public:
    struct Status{
        int leftSum, rightSum, maxSum, Sum;
    };
    
    Status pushUp(Status sub1, Status sub2){
        int leftSum = max(sub1.leftSum, sub1.Sum + sub2. leftSum);
        int rightSum = max(sub2.rightSum, sub2.Sum + sub1.rightSum);
        int maxSum = max(max(sub1.maxSum, sub2.maxSum), sub1.rightSum + sub2.leftSum);
        int Sum = sub1.Sum + sub2.Sum;
        return Status {leftSum, rightSum, maxSum, Sum};
    }
    Status get(vector<int>& nums, int left, int right){
        if(left == right)
            return Status{nums[left], nums[left], nums[left], nums[left]};
        int mid = left + (right - left) / 2;
        Status leftSub = get(nums, left, mid);
        Status rightSub = get(nums, mid + 1, right);
        return pushUp(leftSub, rightSub);        
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).maxSum;
    }
};