#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int size = height.size();
        vector<int> rightmax(size);
        vector<int> leftmax(size);

        leftmax[0] = height[0];
        for (int i = 1; i < size; ++i)
        {
            leftmax[i] = max(leftmax[i - 1], height[i]);
        }

        rightmax[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; --i)
        {
            rightmax[i] = max(rightmax[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < size; ++i)
        {
            ans += min(leftmax[i], rightmax[i]) - height[i];
        }
        return ans;
    }
};

int main()
{
    Solution sul;
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(5);
    cout << sul.trap(nums);
    return 0;
}