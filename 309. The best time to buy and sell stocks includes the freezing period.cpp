#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//309. 最佳买卖股票时机含冷冻期 https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/
//动态规划 分四个状态 0——买入了股票，或者买入并且持有股票 1——卖出并且持有股票 2——卖出了股票 3——冷冻期
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(4));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[0][3] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i-1][0],max(dp[i-1][3] - prices[i],dp[i-1][1] - prices[i])); //保持先前状态，或者先前是冷冻期或是正常持有卖出股票
            dp[i][1] = max(dp[i-1][1],dp[i-1][3]); //保持先前状态，或者是冷冻期状态
            dp[i][2] = dp[i-1][0] + prices[i];
            dp[i][3] = dp[i-1][2];
        }
        return max(dp[prices.size()-1][1],max(dp[prices.size()-1][2],dp[prices.size()-1][3]));
    }
};
int main()
{
    
    system("Pause");
}
