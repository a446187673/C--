#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//452. 用最少数量的箭引爆气球 https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/
//思路如下

class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b)
    {
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp); //排序后数组首部对齐，方便比较
        int res = 1;
        if(points.size() == 0)
            res = 0;
        else
            res = 1;
        for (int i = 1; i < points.size(); i++) //从第二个范围算起
        {
            if(points[i][0] <= points[i-1][1])
            {
                points[i][1] = min(points[i][1],points[i-1][1]);  //若满足条件则缩小范围
            }
            else
            {
                res++;
            }
        }
        return res;
    }
};
int main()
{
    
    system("Pause");
}
