// 一刷：2022 03 16 不会做
// 二刷：2022 03 17 大概会做，不熟练
// 三刷：2022 03 18 大概会做，卡了 mergeSort 的 if 判断

class Solution {
public:
    vector<int> temp;

    void mergeSort(vector<int>& nums, int left, int right){
        if(left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        
        int i = left, j = mid + 1;
        int cnt = 0;
        while(i <= mid && j <= right){
            if(nums[i] < nums[j])
                temp[cnt++] = nums[i++];
            else
                temp[cnt++] = nums[j++];
        }
        while(i <= mid)
            temp[cnt++] = nums[i++];
        while(j <= right)
            temp[cnt++] = nums[j++];
        
        for(int i = 0; i < cnt; ++i){
            nums[left + i] = temp[i];
        }

    }

    vector<int> sortArray(vector<int>& nums) {
        temp.resize(nums.size(), 0);
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};