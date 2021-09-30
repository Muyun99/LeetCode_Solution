class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        int s1 = (ax2 - ax1) * (ay2 - ay1);
        int s2 = (bx2 - bx1) * (by2 - by1);

        // 重叠区域的 x 为短的右边减去长的左边
        // 重叠区域的 y 为短的上边减去长的上边
        // 再与0比较
        int s3 = max(0, min(ax2, bx2) - max(ax1, bx1)) * max(0, min(ay2, by2) - max(ay1, by1));
        return s1 + s2 - s3;
    }
};