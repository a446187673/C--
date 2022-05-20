#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<algorithm>

using namespace std;
//436. 寻找右区间 https://leetcode.cn/problems/find-right-interval/
// class Solution {
// public:
//     vector<int> findRightInterval(vector<vector<int>>& intervals) {
//         vector<int> res;
//         for(vector<int> nums : intervals)
//         {
//             int tempres = INT_MAX;
//             int tempindex = -1;
//             for(int i = 0; i < intervals.size();i++)
//             {
//                 if(intervals[i][0] >= nums[1] && tempres > intervals[i][0])
//                 {
//                     tempres = intervals[i][0];
//                     tempindex = i;
//                 }
//             }
//             res.push_back(tempindex);
//         }
//         return res;
//     }
// };
class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b)
    {
        return a[0]<b[0];
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<vector<int>,int> map;
        for (int i = 0; i < intervals.size(); i++)
        {
            map.emplace(intervals[i],i);
        }
        vector<vector<int>> sorted(intervals.begin(),intervals.end());      
        sort(sorted.begin(),sorted.end(),cmp);
        vector<int> res;
        for(vector<int> nums : intervals)
        {
            // cout<<nums[0]<<","<<nums[1]<<"  ";

            int left = 0;
            int right = sorted.size()-1;
            while (left < right)
            {
                int mid = left + (right - left)/2;
                if(sorted[mid][0] >= nums[1])
                {
                    right = mid;
                }
                else if(sorted[mid][0] < nums[1])
                {
                    left = mid+1;
                }
            }
            if(sorted[left][0] <= nums[1])
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(map[sorted[left]]);
            }
        }
        return res;
    }
};
int main()
{
    Solution s1;
    vector<vector<int>> vec{{3,4},{2,3},{1,2}};
    s1.findRightInterval(vec);
    
    system("Pause");
}
