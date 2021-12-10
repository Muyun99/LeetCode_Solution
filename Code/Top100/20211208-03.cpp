class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> occ;
        int size = s.size();
        int ans = 0;
        int left = -1;
        for (int i = 0; i < size; ++i)
        {
            if (i != 0)
                occ.erase(s[i - 1]);

            while (left + 1 < size && !occ.count(s[left + 1]))
            {
                occ.insert(s[left + 1]);
                ++left;
            }
            ans = max(ans, left - i + 1);
        }
        return ans;
    }
};