class Solution
{
public:
    char Up(char ch)
    {
        if (ch <= 'z' && ch >= 'a')
            ch -= 32;
        return ch;
    }
    string licenseKeyFormatting(string s, int k)
    {
        int size = s.size();
        int num_char = 0;
        string newstr;
        string ans;
        for (int i = 0; i < size; ++i)
        {
            if (s[i] != '-')
            {
                num_char += 1;
                newstr.push_back(Up(s[i]));
            }
        }
        int num_char_first = num_char % k;
        size = newstr.size();
        for (int i = size - 1; i >= 0; --i)
        {
            ans.push_back(newstr[i]);
            if ((size - i) % k == 0 && i != 0)
                ans.push_back('-');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};