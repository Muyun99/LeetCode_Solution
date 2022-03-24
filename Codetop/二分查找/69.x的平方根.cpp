// 一刷：2022 03 19 不会做
// 一刷：2022 03 21 二分会做，牛顿法不会做
// 一刷：2022 03 22 二分会做，牛顿法不会做

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

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;
            
        double prexi = 0;
        double xi = x;
        while(true){
            prexi = xi;
            xi = 0.5 * (xi + (double) x / xi);

            if(fabs(prexi - xi < 1e-7))
                break;
        }
        return (int)xi;
    }
};