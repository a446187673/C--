#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//14. 最长公共前缀 https://leetcode.cn/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minsize = INT_MAX;
        string res;
        for(string s : strs)
        {
            int a = s.size();
            minsize = min(minsize,a);
        }
        for (int i = 0; i < minsize; i++)
        {
            int count = 1;
            for (int j = 1; j < strs.size(); j++)
            {
                if(strs[j][i]  == strs[j-1][i]) //纵向查找
                    count++;
                    
            }
            if(count == strs.size())
                res.push_back(strs[0][i]); //都相等就推入
            else
                break;
            
        }
        return res;
    }
};
int main()
{
    Solution s1;
    vector<string> strs = {"flower","flow","flight"};
    s1.longestCommonPrefix(strs);
    system("Pause");
}
