// 二分查找
// 时间复杂度：O(logx)，即为二分查找需要的次数。
// 空间复杂度：O(1)


class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

// 牛顿迭代法
