class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 0;
        int right = x;
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if ((long long)middle * middle > x)
                right = middle - 1;
            else if (middle * middle < x)
                left = middle + 1;
            else
                return middle;
        }
        return right;
    }
};