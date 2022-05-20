#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//377. 组合总和 Ⅳ https://leetcode.cn/problems/combination-sum-iv/
//完全背包问题 先遍历背包，再遍历物品，这样背包在每个重量的情况都会计算此前所有元素。
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp (target+1,0);
        dp[0]= 1;
        int res = 0;
        for (int i = 0 ; i <= target; i++) //遍历背包
        {
            for (int j = 0 ; j < nums.size(); j++) //遍历物品
            {
                if(i-nums[j] >= 0)
                    dp[i] += dp[i-nums[j]];
                    cout<<dp[i]<<" ";
            }
            cout<<endl;
        }
        
        return dp[target];

    }
};
int main()
{
         Solution s1;
     vector<int> vec{1,2,3};
     cout<<s1.combinationSum4(vec,3);
    
    system("Pause");
}
