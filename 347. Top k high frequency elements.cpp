#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;
//347. 前 K 个高频元素 https://leetcode.cn/problems/top-k-frequent-elements/
class Solution {
public:
    static bool cmp(pair<int,int> p1,pair<int,int> p2)
    {
        return p1.second > p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        vector<int> res;
        for(int i : nums)
        {
            m[i]++;
        }
        vector<pair<int,int>> t;
        for(auto p : m)
            t.push_back(p);
        sort(t.begin(),t.end(),cmp);
        for (int i = 0; i < k; i++)
        {
            res.push_back(t[i].first);
        }
        
        return res;
    }
};
int main()
{
    Solution s1;
    vector<int> vec = {4,1,-1,2,-1,2,3};
    s1.topKFrequent(vec,2);
    system("Pause");
}
