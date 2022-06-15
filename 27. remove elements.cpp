#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//27. 移除元素 https://leetcode.cn/problems/remove-element/
//迭代器法
class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        
        for(vector<int>::iterator it = nums.begin(); it != nums.end();)
        {
            if(*it == val)
                it = nums.erase(it);
            else
                it++;
        }
        return nums.size();
    }
};
//双指针法
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fastidx = 0;
        int slowidx = 0;
        for (; fastidx<nums.size(); fastidx++)
        {
            if (val != nums[fastidx])
            {
                nums[slowidx] = nums[fastidx];
                slowidx++;
            }
        }
        return slowidx;
    }
};

int main()
{
    Solution s1;
    vector<int> nums{3,2,2,3};
    cout<<s1.removeElement(nums,3);
    system("Pause");
}
