#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//462. 最少移动次数使数组元素相等 II https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-ii/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(),nums.end());
        int target = nums[nums.size()/2];
        int res = 0;
        for(int i : nums)
            res += abs(target - i);
        return res;
    }
};
int main()
{
    Solution s1;
    vector<int> vec{1,2,3};
    cout<<s1.minMoves2(vec)<<endl;
    system("Pause");
}
