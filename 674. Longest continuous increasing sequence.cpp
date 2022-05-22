#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//674. 最长连续递增序列 https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
//贪心算法
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int temp = 1;
        int res = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i-1])
            {
                temp++;
                res = max(temp,res);
            }
            else
                temp = 1;
        }
        return res;
    }
};
//动态规划
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int result = 1;
        vector<int> dp(nums.size() ,1);
        for (int i = 0; i < nums.size() - 1; i++) 
        {
            if (nums[i + 1] > nums[i]) 
            {                                       // 连续记录
                dp[i + 1] = dp[i] + 1;
            }
            if (dp[i + 1] > result) 
                result = dp[i + 1];
        }
        return result;
    }
};
int main()
{
    
    system("Pause");
}
