#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//213. 打家劫舍 II https://leetcode.cn/problems/house-robber-ii/
class Solution {
public:
    int oldrob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]); //两条世界线，一条偷一条不偷，如果发现另一条更优就跳转
        }
        return dp[nums.size()-1];
        
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 2)
            return max(nums[0],nums[1]);

        vector<int> nums1(nums.begin(),nums.end()-1); //如果是环形那么排除最前或者最后一个就可以用旧方法算了
        vector<int> nums2(nums.begin()+1,nums.end());
        int res1 = oldrob(nums1);
        int res2 = oldrob(nums2);
        return max(res1,res2);
    }
};
int main()
{
    
    system("Pause");
}
