#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
//467. 环绕字符串中唯一的子字符串 https://leetcode.cn/problems/unique-substrings-in-wraparound-string/
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26,0);
        int k = 0;
        for (int i = 0; i < p.size(); i++)
        {
            if( i>0 && (p[i] - p[i-1]+26) % 26 == 1)//判断i后的字符串是否连续
                k++;    //如果连续，则多一个子串
            else
                k = 1;  //如果不连续，则子串为1
                dp[p[i] - 'a'] = max(dp[p[i] - 'a'],k);
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};
using namespace std;

int main()
{
    
    system("Pause");
}
