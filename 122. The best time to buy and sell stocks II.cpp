#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//122. 买卖股票的最佳时机 II https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
//贪心算法
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            profit = prices[i] - prices[i-1]; //只收集利润为正的情况
            if(profit > 0 )
                res+= profit;
        }
        return res;
    }
};
//动态规划
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]-prices[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i]);
        }
        return dp[prices.size()-1][1];

    }
};
int main()
{
    
    system("Pause");
}
