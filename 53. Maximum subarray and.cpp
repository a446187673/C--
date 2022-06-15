#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//53. 最大子数组和 https://leetcode.cn/problems/maximum-subarray/
//贪心算法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int temp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            temp += nums[i];
            res = max(temp,res);
            if(temp < 0)
                temp = 0;
        }
        return res;
    }
};
//动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 状态转移公式
            if (dp[i] > result) result = dp[i]; // result 保存dp[i]的最大值
        }
        return result;
    }
};
int main()
{
    
    system("Pause");
}
