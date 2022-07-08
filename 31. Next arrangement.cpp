#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//31. 下一个排列 https://leetcode.cn/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while(i >= 0 && nums[i] >= nums[i+1]) //寻找非降序的i
            i--;
        if(i >= 0)
        {
            int j = nums.size()-1;
            while(j > i && nums[i] >= nums[j])
                j--; //寻找nums[i] >= nums[j]
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end()); //交换
    }
};
int main()
{
    
    system("Pause");
}
