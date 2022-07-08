#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;
//454. 四数相加 II https://leetcode.cn/problems/4sum-ii/
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> map;
        for(int i : nums1)
        {
            for(int j : nums2)
            {
                map[i+j]++;
            }
        }
        int res = 0;
        for(int i : nums3)
        {
            for(int j : nums4)
            {
                if(map[-(i + j)] > 0)
                {
                    res+=map[-(i+j)]
                }
            }
        }
        return res;
    }
};
int main()
{
    
    system("Pause");
}
