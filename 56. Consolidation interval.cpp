#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//56. 合并区间 https://leetcode.cn/problems/merge-intervals/
//思路 
class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b)
    {
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        vector<int> temp;
        bool ispush = true;
        for(int i = 1;i < intervals.size();i++)
        {
            if(res.back()[1] >= intervals[i][0])
            {
                res.back()[1] = max(res.back()[1],intervals[i][1]);
            }
            else
            {
                res.push_back({intervals[i][0],intervals[i][1]});
            }
        }
        return res;
    }
};
int main()
{
    
    system("Pause");
}
