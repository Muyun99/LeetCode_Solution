//给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
//示例 1:

//输入: coins = [1, 2, 5], amount = 11
//输出: 3 
//解释: 11 = 5 + 5 + 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dptable(amount+1,amount+1);
        dptable[0] = 0;
        int size = coins.size();
        for(int i = 1;i <= amount;++i){
            for(int j = 0;j < size;++j){
                if(i >= coins[j])
                    dptable[i] = min(dptable[i], dptable[i-coins[j]]+1);
            }
        }
        if(dptable[amount] == amount+1)
            return -1;
        else
            return dptable[amount];
    }
};

int main(){
    class Solution S;
    int coins[3] = {1,2,5};
    vector<int> coinsVector(coins, coins+3);
    int amount = 11;

    cout << S.coinChange(coinsVector, amount);
}