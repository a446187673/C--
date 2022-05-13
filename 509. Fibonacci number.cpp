#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//509. 斐波那契数 https://leetcode.cn/problems/fibonacci-number/
//思路 动态规划 
class Solution {
public:
    int fib(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        vector<int> dp(n+1,0);
        dp[1] = 1;
        int res;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i-2]+dp[i-1]; //dp数组
            res = dp[i];
        }
        return res;
    }
};
int main()
{
    Solution s1;
    cout<<s1.fib(5);
    system("Pause");
}
