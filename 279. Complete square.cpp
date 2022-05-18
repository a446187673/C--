#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//279. 完全平方数 https://leetcode.cn/problems/perfect-squares/
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        int square = 0;
        for (int i = 1; square <= n; i++)
        {
            square = i*i;
            squares.push_back(square);
        }
        squares.pop_back();

        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < squares.size(); i++)
        {
            for (int j = squares[i]; j <= n; j++)
            {
                // if(j-squares[i] != INT_MAX)  //平方数必含有1，不用考虑从从dp[0]以外开始写入的情况
                    dp[j] = min(dp[j - squares[i]] + 1,dp[j]);
            }
            for(int i :dp)
                cout<<i<<" ";
            cout<<endl;
        }
        return dp[n];
        
        
    }
};
int main()
{
    Solution s1;
    cout << s1.numSquares(2);
    system("Pause");
}
