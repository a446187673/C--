#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//494. 目标和 https://leetcode.cn/problems/target-sum/
//01背包 求组合
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i : nums)
            sum +=i;
        if((target + sum) % 2 == 1)
            return 0;
        if(abs(target) > sum)
            return 0;
        int bagsize = (target + sum)/2;
        
        vector<int> dp(bagsize+1,0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = bagsize; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }  
        }
        return dp[bagsize];
        
    }
};
int main()
{
    
    system("Pause");
}
