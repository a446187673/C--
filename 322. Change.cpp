#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//322. 零钱兑换 https://leetcode.cn/problems/coin-change/
//完全背包 硬币价值是1，重量是面值，求最小总价值
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                if(dp[j-coins[i]] != INT_MAX) //如果是初始值就跳过
                    dp[j] = min(dp[j],dp[j-coins[i]]+1);
            }
            for(int i :dp)
                cout<<i<<" ";
            cout<<endl;
        }
        if (dp[amount] == INT_MAX) return -1; //说明无法装满
        return dp[amount];
    }
};
int main()
{
    Solution s1;
    vector<int> vec{2};
    s1.coinChange(vec,3);
    system("Pause");
}
