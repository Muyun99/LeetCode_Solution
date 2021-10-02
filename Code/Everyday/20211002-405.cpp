class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
            return "0";

        int flag = 0;

        if (num < 0)
        {
            flag = 1;
            num = num + INT_MAX + 1;
        }

        // 负数最小值处理后会溢出为 0，特殊处理
        if (num == 0 && flag == 1)
            return "80000000";

        string ans = "";
        while (num)
        {
            int yushu = num % 16;
            if (yushu < 10)
                ans.push_back('0' + yushu);
            else
                ans.push_back('a' + yushu - 10);
            num /= 16;
        }

        reverse(ans.begin(), ans.end());
        if (flag == 1)
        {
            if (ans[0] < '2')
                ans[0] = ans[0] + 8;
            else
                ans[0] = ans[0] - '2' + 'a';
        }
        return ans;
    }
};