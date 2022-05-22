#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//718. 最长重复子数组 https://leetcode.cn/problems/maximum-length-of-repeated-subarray/

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dp(nums2.size()+1,0);
        int res = 0;
        for (int i = 1; i < nums1.size(); i++)
        {
            for (int j = nums2.size(); j > 0; j--)
            {
                if(nums1[i-1] == nums2[j-1])
                    dp[j] = dp[j-1]+1;
                else
                    dp[j] = 0;
                res = max(res,dp[j]);
            }
        }
        return res;
    }
};
int main()
{
    
    system("Pause");
}
