#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>

using namespace std;
//139. 单词拆分 https://leetcode.cn/problems/word-break/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(),wordDict.end());
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {   // 遍历背包
            for (int j = 0; j < i; j++) {       // 遍历物品
                string word = s.substr(j, i - j); //substr(起始位置，截取的个数)
                if (words.find(word) != words.end() && dp[j]) {
                    dp[i] = true;
                }
            }
            for(int i :dp)
                cout<<i<<" ";
            cout<<endl;
        }
        
        return dp[s.size()];
    }
};
int main()
{
    Solution s1;
    vector<string> s{"leet", "code"};
    s1.wordBreak("leetcode",s);
    system("Pause");
}
