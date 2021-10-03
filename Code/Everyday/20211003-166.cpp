#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        string ret = "";

        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
            ret.push_back('-');
        numerator = abs(numerator);
        denominator = abs(denominator);

        long beforeDot = numerator / denominator;
        beforeDot = abs(beforeDot);
        ret.append(to_string(beforeDot));

        unordered_map<int, int> dict;
        long rem = numerator % denominator;
        if (rem != 0)
            ret.push_back('.');
        else
            return ret;

        while (rem != 0 && dict.find(rem) == dict.end())
        {
            dict[rem] = ret.size();
            long quo = (rem * 10) / denominator;
            ret.push_back('0' + quo);
            rem = (rem * 10) % denominator;
        }

        if (rem == 0)
            return ret;
        else
        {
            // 发现循环节
            int loc = dict[rem];
            ret.insert(ret.begin() + loc, '(');
            ret.push_back(')');
            return ret;
        }
    }
};

int main()
{
    Solution sol;
    cout << sol.fractionToDecimal(-2147483648, -1);
    return 0;
}