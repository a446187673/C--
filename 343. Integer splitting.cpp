#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//343. 整数拆分 https://leetcode.cn/problems/integer-break/
//思路 动态规划
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i] = max(dp[i],max(dp[i-j]*j,(i-j)*j)); //当前这个数，所有分割情况取最大的
                                                            //一种是直接分割两个数，另一种是前面所有分割情况最大的乘分割数。
            }
        }
        return dp[n];
        
    }
};
int main()
{
    
    system("Pause");
}
