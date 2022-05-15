#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//812. 最大三角形面积 https://leetcode.cn/problems/largest-triangle-area/
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0;
        int n = points.size();
        for (int i = 0; i < n-2; i++)
        {
            for (int j = 0; j < n-1; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    vector<int> p1 = points[i];
                    vector<int> p2 = points[j];
                    vector<int> p3 = points[k];
                    int x1 = p1[0],y1 = p1[1];
                    int x2 = p2[0],y2 = p2[1];
                    int x3 = p3[0],y3 = p3[1];
                    res = max(res,0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
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
