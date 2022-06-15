#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//209. 长度最小的子数组 https://leetcode.cn/problems/minimum-size-subarray-sum/
//滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int res = INT_MAX;
        while(right < nums.size())
        {
            int cursum = 0;
            for (int j = left; j <= right; j++)
                cursum += nums[j];
            if(cursum >= target)
            {
                res = min(right-left+1,res);
                left++;
            }
            else if(cursum < target)
            {
                right++;
            }
        }
        return res;
    }
};
int main()
{
    Solution s1;
    vector<int> vec{1,2,3,4,5};
    cout<<s1.minSubArrayLen(11,vec);
    system("Pause");
}
