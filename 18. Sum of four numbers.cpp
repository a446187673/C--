#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//18. 四数之和 https://leetcode.cn/problems/4sum/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > target && ( nums[i] >= 0 || target >= 0))
                break;
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i+1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] > target && ( nums[i] + nums[j] >= 0 || target >= 0))
                    continue;
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                
                int left = j + 1;
                int right = nums.size()-1;
                
                while (left < right)
                {
                    if(nums[i] + nums[j] < target- (nums[left] + nums[right]))
                    {
                        left++;
                        while(left < right && nums[left] == nums[left -1])
                            left++;
                    }
                    else if(nums[i] + nums[j] > target- (nums[left] + nums[right]))
                    {
                        right--;
                        while(left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                    else
                    {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        while(left < right && nums[left] == nums[left -1])
                            left++;
                         while(left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                }
            }
        }
        return res;
    }
};
int main()
{
    Solution s1;
    vector<int> vec{1,0,-1,0,-2,2};
    s1.fourSum(vec,0);
    system("Pause");
}
