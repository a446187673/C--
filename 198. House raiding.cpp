#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//198. 打家劫舍 https://leetcode.cn/problems/house-robber/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 0)
            return 0;
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]); //两条世界线，一条偷一条不偷，如果发现另一条更优就跳转
        }
        return dp[nums.size()-1];
        
    }
};
int main()
{
    
    system("Pause");
}
