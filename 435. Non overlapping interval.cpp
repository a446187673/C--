#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//435. 无重叠区间 https://leetcode.cn/problems/non-overlapping-intervals/
//思路 1.按照右边界排序，右边界越小越好
//2.记录不发生重叠时的各个边界
class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int notr = 1;
        int sign = intervals[0][1];
        for(int i = 1;i < intervals.size();i++)
        {
            if(intervals[i][0]>=sign)
            {
                sign = intervals[i][1];
                notr++;
            }
        }
        return intervals.size()-notr;
    }
};
int main()
{
    Solution s1;
    vector<vector<int>> s{{1,2},{2,3},{3,4},{1,3}};
    cout<<s1.eraseOverlapIntervals(s);
    system("Pause");
}
