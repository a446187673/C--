#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<string>
#include<algorithm>

using namespace std;
//349. 两个数组的交集 https://leetcode.cn/problems/intersection-of-two-arrays/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        set<int> set;
        vector<int> res;
        for(int i : nums1)
            map[i]++;
        for(int i : nums2)
        {
            if(map[i] > 0)
                set.emplace(i);
        }
        for(int i : set)
            res.push_back(i);
        return res;
    }
};
int main()
{
    
    system("Pause");
}
