#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//704. 二分查找 https://leetcode.cn/problems/binary-search/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left < right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        if(nums[left] == target)
            return left;
        else
            return -1;
    }
};
int main()
{
    Solution s1;
    vector<int> vec{-1,0,3,5,9,12};
    cout<<s1.search(vec,9);
    system("Pause");
}
