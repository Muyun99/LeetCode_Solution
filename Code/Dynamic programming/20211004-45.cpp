#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int size = nums.size();
        int rightmost = 0;
        int step = 0;
        int end = 0;
        for (int i = 0; i < size - 1; ++i)
        {
            if (i <= rightmost)
            {
                rightmost = max(rightmost, i + nums[i]);
                if (i == end)
                {
                    step++;
                    end = rightmost;
                }
            }
        }
        return step;
    }
};

int main()
{
    Solution sul;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(4);
    cout << sul.jump(nums);
    return 0;
}