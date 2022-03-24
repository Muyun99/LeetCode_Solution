// 一刷：2022 03 22 会做归并排序，其他做法不会

// 基于归并排序的算法: 
// - 时间复杂度O(nlogn)
// - 空间复杂度是新数组的空间 O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> newnums (size1 + size2);

        int i = 0;
        int j = 0;
        int cnt = 0;
        while(i < size1 && j < size2){
            if(nums1[i] < nums2[j])
                newnums[cnt++] = nums1[i++];
            else
                newnums[cnt++] = nums2[j++];
        }
        while(i < size1)
            newnums[cnt++] = nums1[i++];
        while(j < size2)
            newnums[cnt++] = nums2[j++];
        
        if((cnt) % 2 == 1)
            return newnums[(cnt) / 2];
        else
            return (newnums[(cnt) / 2] + newnums[(cnt) / 2 - 1])  / 2.0;
    }   
};