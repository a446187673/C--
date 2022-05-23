#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//392. 判断子序列 https://leetcode.cn/problems/is-subsequence/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
        bool haves = false;
        for (int i = 1; i <= s.size(); i++)
        {
            haves = false;
            for (int j = 1; j <= t.size(); j++)
            {
                
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    haves = true;
                }
                else
                {
                    dp[i][j] = dp[i][j-1]; //遇到相同再同步
                }
                    
            }
            if(haves != true)
                return false;
        }
        if(dp[s.size()][t.size()] == s.size())
            return true;
        else
            return false;
        
    }
};
int main()
{
    
    system("Pause");
}
