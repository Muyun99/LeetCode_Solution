class Solution {
public:
    int partition(vector<int>& nums, int l, int r){
        int pivot = nums[r];
        int i = l - 1;
        for(int j = l; j <= r - 1; ++j){
            if(nums[j] <= pivot){
                ++i;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[r]);
        return i + 1;
    }

    int quicksort_partition(vector<int>& nums, int l, int r){
        int i = rand() % (r - l + 1) + l;
        swap(nums[i], nums[r]);        
        return partition(nums, l, r);
    }

    void quicksort(vector<int>& nums, int l, int r){
        if(l < r){
            int pos = quicksort_partition(nums, l, r);
            quicksort(nums, l, pos - 1);
            quicksort(nums, pos + 1, r);
        }
        
    }
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        quicksort(nums, 0, size-1);
        return nums;
    }
};