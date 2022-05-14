#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//746. 使用最小花费爬楼梯 https://leetcode.cn/problems/min-cost-climbing-stairs/
//思路 动态规划
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++)
        {
            dp[i] = min(dp[i-1],dp[i-2]) + cost[i]; //前次跳跃花费加当前花费
        }
        for(int i : dp) //打印dp数组
            cout<<i<<" ";
        return min(dp[n-1],dp[n-2]); //最后一次的花费不需要
    }
};
int main()
{
    Solution s;
    vector<int> cost{10,15,1000};
    s.minCostClimbingStairs(cost);
    system("Pause");
}
