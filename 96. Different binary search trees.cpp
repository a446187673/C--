#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//96. 不同的二叉搜索树 https://leetcode.cn/problems/unique-binary-search-trees/
//思路 动态规划 每次dp[i]向前取，实际上都是在前一种情况后接上树
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += dp[j-1] * dp[i-j];
            }
            
        }
        return dp[n];
    }
};
int main()
{
    
    system("Pause");
}
