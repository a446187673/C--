#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//84. 柱状图中最大的矩形 https://leetcode.cn/problems/largest-rectangle-in-histogram/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        vector<int> lm(size);
        vector<int> rm(size);
        
        lm[0] = -1;
        for (int i = 1; i < size; i++)
        {
            int t = i - 1;
            while (t >= 0 && heights[t] >= heights[i]) //向左寻找的过程,t停留在找到的位置
            {
                t = lm[t];
            }
            lm[i] = t;
        }
        rm[size-1] = size;
        for (int i = size - 2; i >= 0; i--) //向右寻找
        {
            int t = i + 1;
            while (t < size && heights[t] >= heights[i]) 
            {
                t = rm[t];
            }
            rm[i] = t;
            
        }
        
        int res = 0;
        for (int i = 0; i < size; i++)
        {
            int temp = heights[i]*abs(rm[i] - lm[i]-1);
            res = max(res,temp);
        }
        
        return res;
        
    }
};
int main()
{
    Solution s1;
    vector<int> h{2,1,5,6,2,3};
    s1.largestRectangleArea(h);
    
    system("Pause");
}
