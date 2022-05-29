#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//42. 接雨水 https://leetcode.cn/problems/trapping-rain-water/
class Solution1 { //双指针法
public:
    int trap(vector<int>& height) {
        int res = 0;
        for (int i = 0; i < height.size(); i++)
        {
            if(i == 0 || i == height.size()-1)
                continue;
            int lh = height[i];
            int rh = height[i];

            for (int j = i+1; j < height.size(); j++)
                rh = max(rh,height[j]);
                
            for (int j = i-1; j >= 0; j--)
                lh = max(lh,height[j]);

            int h = min(lh,rh) - height[i];

            if(h > 0)
                res += h;
        }
        return res;
    }
};
class Solution2 { //动态规划
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2)
            return 0;
        int size = height.size();
        vector<int> lh(size,0);
        vector<int> rh(size,0);

        lh[0] = height[0];
        for (int i = 1; i < size; i++) //记录每个柱子左边柱子的最大高度（包括柱子自己）
            lh[i] = max(lh[i-1],height[i]);
        
        rh[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--)//右边
            rh[i] = max(rh[i+1],height[i]);
        
        int res = 0;
        for (int i = 0; i < size; i++)
        {
            int temp = min(lh[i],rh[i]) - height[i];
            if(temp > 0)
                res += temp;
        }
        
        return res;
    }
};
int main()
{
    
    system("Pause");
}
