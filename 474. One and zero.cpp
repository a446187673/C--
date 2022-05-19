#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//474. 一和零 https://leetcode.cn/problems/ones-and-zeroes/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,(vector<int>(n+1,0)));
        for(string s : strs) //遍历物品
        {
            int onenum = 0, zeronum = 0;
                for(char c : s)
                {
                    if(c == '0')
                        zeronum++;
                    else
                        onenum++;
                }
            for (int i = m; i >= zeronum; i--)//遍历背包
            {
                for (int j = n; j >= onenum; j--)
                {
                    dp[i][j] = max(dp[i][j] , dp[i-zeronum][j-onenum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
int main()
{
    Solution s1;
    vector<string> vec{"10","0001","111001","1","0"};
    s1.findMaxForm(vec,5,3);
    system("Pause");
}
