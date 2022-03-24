// 一刷：2022 03 22 不会做

// 基于优先队列的算法: 
// - 时间复杂度O(nlogn)，
// - 空间复杂度是队列的栈的空间 O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        priority_queue<pair<int, int>> pq;
        for(int i = 0;i < k; ++i){
            pq.emplace(nums[i], i);
        }
        vector<int> ans = {pq.top().first};
        for(int i = k; i < size; ++i){
            pq.emplace(nums[i], i);
            while(pq.top().second <= i - k)
                pq.pop();
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};

// 基于单调队列的算法: 
// - 时间复杂度O(nlogn)，
// - 空间复杂度是队列的栈的空间 O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        vector<int> ans = {nums[q.front()]};
        for (int i = k; i < n; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
            while (q.front() <= i - k) {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};