// 贪心做法
class Solution
{
public:
    int findMinMoves(vector<int> &machines)
    {
        int sum = 0;
        int size = machines.size();
        for (int i = 0; i < size; i++)
            sum += machines[i];
        if (sum % size != 0)
            return -1;
        int mean = sum / size;

        int ans = 0;
        int presum = 0;
        for (int i = 0; i < size; ++i)
        {
            presum += machines[i];
            ans = max(ans, max(machines[i] - mean, abs(presum - mean * (i + 1))));
        }

        return ans;
    }
};