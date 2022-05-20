#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//121. 买卖股票的最佳时机 https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
//贪心算法
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int minvalue = INT_MAX;
        int res = 0;
        for(int value : prices)
        {
            minvalue = min(value,minvalue); //每次都记录最小值并且尝试卖出
            int profit = value- minvalue;
            res = max(res,profit);
        }
        return res;
    }
};
//动态规划
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;

        vector<vector<int>> dp(prices.size(),vector<int>(2));

        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i-1][0],-prices[i]);
            dp[i][1] = max(dp[i-1][1],prices[i] + dp[i-1][0]);
        }
        return dp[prices.size()-1][1];

    }
};
int main()
{
    
    system("Pause");
}
