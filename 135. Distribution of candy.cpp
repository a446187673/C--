#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//135. 分发糖果 https://leetcode-cn.com/problems/candy/
//思路 1.先从前向后比较每个孩子（比较ratings[i]是否大于ratings[i-1]，如果大于就在前一个数的基础再加1）
//2.同理，从右向左比较，做相同判断，取max(kandys[i+1]+1,kandys[i])，保证在任何时候中间的值都为最大。
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> kandys(ratings.size(),1);
        for (int i = 1; i < ratings.size(); i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                kandys[i] = kandys[i-1] + 1;
            }
        }
        for(int i = ratings.size()-2; i >=0; i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                kandys[i] = max(kandys[i+1]+1,kandys[i]);
            }
        }
        int sum= 0;
        for(int i : kandys)
            sum+=i;
        return sum;
    }
};
int main()
{
    
    system("Pause");
}
