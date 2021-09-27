class Solution
{
public:
    int onecharcheck(char ch)
    {
        if (ch == '0')
            return 0;
        if (ch == '*')
            return 9;
        else
            return 1;
    }
    // ch1 是s[n-1],ch2是s[n]
    int twocharcheck(char ch1, char ch2)
    {
        if (ch1 == '0')
            return 0;
        else if (ch1 == '1')
        {
            if (ch2 == '*')
                return 9;
            else
                return 1;
        }
        else if (ch1 == '2')
        {
            if (ch2 == '*')
                return 6;
            else if ('0' - 1 < ch2 && ch2 < '7')
                return 1;
            else
                return 0;
        }

        else if (ch1 == '*')
        {
            if (ch2 == '*')
                return 15;
            else if (ch2 < '7')
                return 2;
            else
                return 1;
        }
        else
            return 0;
    }
    int numDecodings(string s)
    {
        //动态规划
        // ans[n] = max(ans[n-1] * cost(s[n]), ans[n-2] * cost(s[n], s[n-1]));
        // n = 1 ans[n] = cost(s[n])
        // n = 2 ans[n] = cost(s[n], s[n-1])

        int mod = 1000000007;
        int length_s = s.size();

        vector<long long> ans(length_s + 1);
        ans[0] = 1;
        // a = f[i-2], b = f[i-1], c = f[i]
        for (int i = 1; i <= length_s; ++i)
        {
            if (i == 1)
                ans[i] = (long long)ans[i - 1] * onecharcheck(s[i - 1]) % mod;
            else
                ans[i] = ((long long)ans[i - 1] * onecharcheck(s[i - 1]) + (long long)ans[i - 2] * twocharcheck(s[i - 2], s[i - 1])) % mod;
        }
        return ans[length_s];

        // int a = 0, b = 1, c = 0;
        // for (int i = 1; i <= length_s; ++i){
        //     c = (long long)b * onecharcheck(s[i - 1]) % mod;
        //     if (i > 1) {
        //         c = (c + (long long)a * twocharcheck(s[i - 2], s[i - 1])) % mod;
        //     }
        //     a = b;
        //     b = c;
        // }
        // return c;
    }
};