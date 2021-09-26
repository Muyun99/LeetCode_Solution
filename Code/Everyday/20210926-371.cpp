class Solution
{
public:
    int getSum(int a, int b)
    {
        unsigned int carry;
        while (b != 0)
        {
            carry = (unsigned int)(a & b) << 1;
            a = (a ^ b);
            b = carry;
        }
        return a;
    }
};