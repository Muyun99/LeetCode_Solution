// 一刷：2022 03 17 不会做

// 双指针
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        int size = numbers.size();
        while(left < right){
            if(numbers[left] + numbers[right] < target)
                ++left;
            else if(numbers[left] + numbers[right] > target)
                --right;
            else
                return {left+1, right+1};

        }
        return {};
        
    }
};

// 二分查找
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int low = i + 1, high = numbers.size() - 1;
            while (low <= high) {
                int mid = (high - low) / 2 + low;
                if (numbers[mid] == target - numbers[i]) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] > target - numbers[i]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return {-1, -1};
    }
};