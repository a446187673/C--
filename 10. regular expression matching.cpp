*#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//10. 正则表达式匹配 https://leetcode.cn/problems/regular-expression-matching/
//动态规划，图解力扣发布题解 https://leetcode.cn/problems/regular-expression-matching/solution/by-distracted-villanihkb-qk8q/
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
        dp[0][0] = true;
        for (int i = 1; i <= p.size(); i++)
        {
            if(p[i-1] == '*')
                dp[0][i] = dp[0][i-2]; //匹配空字符遇到*号,则取前面的前面的数字
        }
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                {
                    if(p[j-2] == s[i-1] || p[j-2] == '.')
                        dp[i][j] = dp[i][j-2] || dp[i-1][(j-1)-1] ||dp[i-1][j];
                        //匹配0次，匹配1次，匹配多次
                    else
                        dp[i][j] = dp[i][j-2]; //必须匹配0次
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
int main()
{
    
    system("Pause");
}
