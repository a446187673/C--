#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//473. 火柴拼正方形 https://leetcode.cn/problems/matchsticks-to-square/
class Solution {
public:
    bool backtracking(vector<int>& matchsticks, int startindex, int length,vector<int>& bucket)
    {
        if(startindex >= matchsticks.size())
        {
            return (bucket[0] == bucket[1]) && (bucket[1] == length) && (bucket[2] == length);
        }
        
        for (int i = 0; i < 4; i++)
        {
            if(bucket[i] + matchsticks[startindex] > length) //查找当前桶
                continue;
            bucket[i] += matchsticks[startindex];
            if(backtracking(matchsticks,startindex+1,length,bucket))
                return true;
            bucket[i] -= matchsticks[startindex];
        }
        return false;
    }
    static bool cmp(int a,int b)
    {
        return a>b;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(int i : matchsticks)
            sum += i;
        sort(matchsticks.begin(),matchsticks.end(),cmp);
        vector<int> bucket(4,0);
        if(matchsticks.size() >= 4 && sum % 4 == 0)
            return backtracking(matchsticks,0,sum/4,bucket);

        return false;
    }
};
int main()
{
    Solution s1;
    vector<int> vec{5,5,5,5,4,4,4,4,3,3,3,3};
    s1.makesquare(vec);
    system("Pause");
}
