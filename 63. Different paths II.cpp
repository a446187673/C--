#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//63. 不同路径 II https://leetcode.cn/problems/unique-paths-ii/
//思路 动态规划
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for (int i = 0; i < m ; i++) //初始化，沿着边走只有一种走法
        { 
            if(obstacleGrid[i][0] == 1) //有障碍后续都初始化不了
                break;
            dp[i][0] = 1;
        }

        for (int i = 0; i < n ; i++)
        { 
            if(obstacleGrid[0][i] == 1)
                break;
            dp[0][i] = 1;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1) //如果遇到障碍就忽略当前格
                    continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1]; //dp公式，每次状态都由上两次再行进一步得
            }
        }
        return dp[m-1][n-1];
        
    }
};
int main()
{
    Solution s1;
    system("Pause");
}
