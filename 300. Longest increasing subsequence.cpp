#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//300. 最长递增子序列 https://leetcode.cn/problems/longest-increasing-subsequence/
//动态规划 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        vector<int> dp(nums.size(),1);
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                    dp[i] = max(dp[j]+1,dp[i]); //位置i的最长升序子序列等于 j从0到i-1各个位置的最长升序子序列 + 1 的最大值
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};
int main()
{
    
    system("Pause");
}
