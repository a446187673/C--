#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;
//961. 在长度 2N 的数组中找出重复 N 次的元素 https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i : nums)
        {
            map[i]++;
            if(map[i] > 1)
                return i;
        }
        return 0;
    }
};
int main()
{
    
    system("Pause");
}
