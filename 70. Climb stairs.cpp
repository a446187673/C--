#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//70. 爬楼梯 https://leetcode.cn/problems/climbing-stairs/
//思路 动态规划
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;
        int res;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i-1]+dp[i-2]; //dp数组
            res = dp[i];
        }
        return res;
    }
};
int main()
{
    
    system("Pause");
}
