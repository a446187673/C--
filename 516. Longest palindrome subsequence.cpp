#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//516. 最长回文子序列 https://leetcode.cn/problems/longest-palindromic-subsequence/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        for (int i = 0; i < s.size(); i++)
        {
            dp[i][i] = 1;
        }
        
        for (int i = s.size()-1; i >= 0; i--)
        {
            for (int j = i+1; j < s.size(); j++) //注意是i+1，不然数组会越界，只有一个数字的时候已经初始化过了 
            {
                if(s[i] == s[j])
                {
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};
int main()
{
    
    system("Pause");
}
