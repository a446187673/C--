#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//442.数组中重复的数据 https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/
//题解 https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/solution/by-fuxuemingzhu-dko5/
//要求空间复杂度为O(1)，不能使用unordered_map, 故原地修改数组
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            int cur = abs(nums[i])-1; //当前下标所对应的值
            nums[cur] = -nums[cur]; //对值的位置取负，记录这个值已被遍历了一次
            if(nums[cur] > 0)
            {
                res.push_back(abs(nums[i])); //如果取完的值为正数，证明该数被遍历了两次，放入结果中
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> a{1,1};
    s.findDuplicates(a);
    system("Pause");
}
