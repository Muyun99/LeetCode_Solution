// 一刷：2022 03 22 不会做
// 二刷：2022 06 09 不会做，滑动窗口经典题

// 滑动窗口
// - 时间复杂度 O(128)， 128是所有字符的数量
// - 空间复杂度 O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charset; 
        int size = s.size();

        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rightIndex = -1;
        int ans = 0;
        
        for(int leftIndex = 0; leftIndex < size; ++leftIndex){
            if(leftIndex > 0)
                charset.erase(s[leftIndex - 1]);

            while(rightIndex + 1 < size && charset.count(s[rightIndex + 1]) == 0){
                ++rightIndex;
                charset.insert(s[rightIndex]);
            }
                
            ans = max(ans, rightIndex - leftIndex + 1);
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charset;
        int size = s.size();

        int rightIndex = -1;
        int ans = 0;

        for(int leftIndex = 0; leftIndex < size; ++leftIndex){
            if(leftIndex > 0)
                charset.erase(s[leftIndex - 1]);

            while(rightIndex + 1 < size && charset.find(s[rightIndex + 1]) == charset.end()){
                ++rightIndex;
                charset.insert(s[rightIndex]); 
            }                   
            ans = max(ans, rightIndex - leftIndex + 1);
            
        }
        return ans;
    }
};