#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//42. 接雨水 https://leetcode.cn/problems/trapping-rain-water/
class Solution {
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
int main()
{
    
    system("Pause");
}
