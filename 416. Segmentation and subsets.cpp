#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//416. 分割等和子集 https://leetcode.cn/problems/partition-equal-subset-sum/
//思路 01背包 动态规划 
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i : nums)
            sum+=i;
        if(sum % 2 == 1)
            return false;
        int target = sum/2;
        vector<int> dp(target+1,0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j],dp[j - nums[i]]+nums[i]);
            }
            for(int i : dp)
                cout<<i<<" ";
            cout<<endl;
            
        }
        if (dp[target] == target) return true;
        return false;
        
    }
};
int main()
{
    Solution s1;
    vector<int> vec{1,1,2,60};
    s1.canPartition(vec);
    system("Pause");
}
