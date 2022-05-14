#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//62. 不同路径 https://leetcode.cn/problems/unique-paths/
//思路 动态规划
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> tmp(n,0);
        vector<vector<int>> dp(m,tmp);
        for (int i = 1; i < m; i++) //初始化，沿着边走只有一种走法
            dp[i][0] = 1;

        for (int i = 0; i < n; i++)
            dp[0][i] = 1;

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1]; //dp公式，每次状态都由上两次再行进一步得
            }
        }
        return dp[m-1][n-1];
        
    }
};
int main()
{
    Solution s1;
    cout<<s1.uniquePaths(3,7);
    system("Pause");
}
