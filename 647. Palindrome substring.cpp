#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//647. 回文子串 https://leetcode.cn/problems/palindromic-substrings/
// class Solution {
// public:
//     bool ishuiwen(string s)
//     {
//         string ss;
//         for (int i = s.size()-1; i >= 0; i--)
//         {
//             ss.push_back(s[i]);
//         }
//         return ss == s?true:false;
//     }
//     int countSubstrings(string s) {
//         int res = 0;
//         for (int i = s.size()-1; i >= 0 ; i--)
//         {
//             for (int j = i; j < s.size(); j++)
//             {
//                 string s1 = s.substr(i,s.size()-j);
//                 if(ishuiwen(s1))
//                     res++;
//             }
//         }
//         return res;
//     }
// }; 超时
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        int res = 0;
        for (int i = s.size()-1; i >= 0; i--)
        {
            for(int j = i; j < s.size(); j++) //从右下角开始遍历
            {
                if(s[i] == s[j])
                {
                    if(j - i <= 1)
                    {
                        res++;
                        dp[i][j] = true;
                    }
                    else if(dp[i+1][j-1] == true)
                    {
                        res++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return res;
    }
};
int main()
{
    Solution s1;
    string s = "abac";
    cout<<s1.countSubstrings("aaa");
    system("Pause");
}
