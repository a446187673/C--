#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//518. 零钱兑换 II https://leetcode.cn/problems/coin-change-2/
//完全背包问题 dp[j- cions[i]]为上个状态下总共的装硬币方法组 ,+=遇到新满足状态的硬币就加一份组合
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp (amount+1,0);
        dp[0]= 1;
        int res = 0;
        
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                if(j-coins[i] >= 0)
                    dp[j] += dp[j-coins[i]];
            }
            for(int i :dp)
                cout<<i<<" ";
            cout<<endl;
        }
        
        return dp[amount];
    }
};
int main()
{
     Solution s1;
     vector<int> vec{1,5};
     cout<<s1.change(6,vec);
    system("Pause");
}
