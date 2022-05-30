#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;
//1365. 有多少小于当前数字的数字 https://leetcode.cn/problems/how-many-numbers-are-smaller-than-the-current-number/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> vec = nums;
        sort(vec.begin(),vec.end());
        vector<int> map(101,-1);
        for (int i = vec.size()-1; i >= 0; i--)
            map[vec[i]] = i;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
            res.push_back(map[nums[i]]);
        return res;
    }
};
int main()
{
    
    system("Pause");
}
