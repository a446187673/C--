#include<iostream>
#include<vector>
#include<string>
#include<multimap>
#include<algorithm>

using namespace std;
//1. 两数之和 https://leetcode.cn/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> res(2);
        for (int i = 0; i < nums.size(); i++)
        {
            if(map.count(target - nums[i]) == 1 )
            {
                res[0] = map[target - nums[i]];
                res[1] = i;
            }
            //判断结束后再加入数字,防止相同数覆盖
            map[nums[i]] = i;
        }
        return res;
    }
};
int main()
{
    
    system("Pause");
}
