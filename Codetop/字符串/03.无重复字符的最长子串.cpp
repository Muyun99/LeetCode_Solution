// 一刷：2022 03 22 不会做

// 滑动窗口
// - 时间复杂度 O(128)， 128是所有字符的数量
// - 空间复杂度 O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charset; 
        int size = s.size();

        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rightindex = -1;
        int ans = 0;
        
        for(int i = 0; i < size; ++i){
            if(i > 0)
                charset.erase(s[i - 1]);

            while(rightindex + 1 < size && charset.count(s[rightindex + 1]) == 0){
                ++rightindex;
                charset.insert(s[rightindex]);
            }
                
            ans = max(ans, rightindex - i + 1);
        }
        return ans;
    }
};