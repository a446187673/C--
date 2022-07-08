#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//15. 三数之和 https://leetcode.cn/problems/3sum/
//三指针 注意每次移动指针后都要去重
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++)
        {
            //不能凑成三数之和的情况
            if(nums[i] > 0)
                return res;
            //去重
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if(nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                    //去重
                    while(left < nums.size() && nums[left] == nums[left - 1])
                        left++;
                }
                else if(nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                    //去重
                    while(right > 0 && nums[right] == nums[right+1])
                        right--;
                }
                else
                {
                    res.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;
                    //去重
                    while(left < nums.size() && nums[left] == nums[left - 1])
                        left++;
                    while(right > 0 && nums[right] == nums[right+1])
                        right--;
                }
            }
        }
        return res;
        
    }
};
int main()
{
    
    system("Pause");
}
