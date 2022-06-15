#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//977. 有序数组的平方 https://leetcode.cn/problems/squares-of-a-sorted-array/
//暴力法
class Solution1 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};
//双指针
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> res;
        while(left < right)
        {
            if(nums[left]*nums[left] >= nums[right]*nums[right])
            {
                res.push_back(nums[left]*nums[left]);
                left++;
            }
            else
            {
                res.push_back(nums[right]*nums[right]);
                right--;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
int main()
{
    
    system("Pause");
}
