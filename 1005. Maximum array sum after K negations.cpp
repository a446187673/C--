#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
// 1005. K 次取反后最大化的数组和 https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations/
//思路：如果当前数组内全部数字大于0，则根据K的奇偶简单处理
//如果数组中有负数，就尝试将负数变为正数并处理。
using namespace std;
class Solution {
public:
    int AllBigger0(vector<int>& nums,int k) // 当数组内全为正数时
    {
        int sum = 0;
        if(k%2 == 0)
        {
            for(int i : nums)
                sum+=i;
        }
        else
        {
            int minnum = INT_MAX;
            for(int i : nums)
            {
                sum+=i;
                if(minnum > i)
                    minnum = i;
            }
            sum = sum-minnum-minnum; //k为奇数，则取最小值变为负数
        }
        return sum;

    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        bool isBigger0 = true;
        for(int i : nums)
        {
            if(i<0)
            {
                isBigger0 = false;
                break;
            }
        }
        if(isBigger0)
        {
            return AllBigger0(nums,k);
        }
        else
        {
            sort(nums.begin(),nums.end());
            for(int i = 0;i<nums.size();i++) //尝试将数组变为全部是正数的数组
            {
                if(nums[i]<0)
                {
                    nums[i] = -nums[i];
                    k--;
                }
                if(k<=0)
                {
                    break;
                }
            }
            if(k<=0) //如果无法全部变为正数，则直接返回
            {
                int sum = 0;
                for(int i : nums)
                    sum+=i;
                return sum;
            }
            else //如果可以全部变为正数，则将剩下的k和数组当做全部是正数的情况处理
            {
                int sum = AllBigger0(nums,k);
                return sum;
            }
        }

    }
};
int main()
{
    
    system("Pause");
}
