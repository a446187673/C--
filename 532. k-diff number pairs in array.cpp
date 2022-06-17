#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//532. 数组中的 k-diff 数对 https://leetcode.cn/problems/k-diff-pairs-in-an-array/
//排序+双指针
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res = 0;
        int record = -999;
        for (int i = 1; i < nums.size(); i++)
        {
            int j = i-1;
            while(j >= 0 && nums[i]-nums[j] < k && j)
            {
                j--;
            }

            while(j >= 0 && nums[i] - nums[j] == k)
            {
                if(record == nums[j])
                    break;
                res++;
                if(j>=0)
                    record = nums[j];
                j--;
            }
            if(j >= 0 && nums[i] - nums[j] > k)
            {
                continue;
            }
        }
        return res;
    }
};
int main()
{
    Solution s1;
    vector<int> vec{-1,0,0,1,0,0,-1};
    cout<<s1.findPairs(vec,1);
    system("Pause");
}
