// 一刷：2022 03 16 不会做
// 二刷：2022 03 17 会做，较熟练
// 三刷：2022 03 18 会做，卡了下
// 四刷：2022 03 19 会做，较熟练
// 五刷：2022 06 09 大概会做，忘记了 quicksort 函数中的 if(left < right)
// 六刷：2022 07 31 大概会做

class Solution {
public:
    void quicksort(vector<int>& nums, int left, int right){
        if(left < right){
            int p = partition(nums, left, right);
            quicksort(nums, left, p - 1);
            quicksort(nums, p + 1, right);
        }
    }
    int partition(vector<int>& nums, int left, int right){
        int selectNum = rand() % (right - left + 1) + left;
        swap(nums[right], nums[selectNum]);
        int p = left - 1;
        for(int i = left; i < right; ++i){
            if(nums[i] < nums[right]){
                ++p;
                swap(nums[p], nums[i]);
            }
        }
        swap(nums[p + 1], nums[right]);
        return p + 1;
    }
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};