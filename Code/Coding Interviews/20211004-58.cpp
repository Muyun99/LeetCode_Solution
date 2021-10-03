class Solution
{
public:
    string reverseLeftWords(string s, int n)
    {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

class Solution
{
public:
    string reverseLeftWords(string s, int n)
    {
        int size = s.size();
        string str;
        for (int i = n; i < size; ++i)
            str.push_back(s[i]);

        for (int i = 0; i < n; ++i)
            str.push_back(s[i]);
        return str;
    }
};