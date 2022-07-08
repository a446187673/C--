#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//剑指 Offer 05. 替换空格 https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
class Solution {
public:
    string replaceSpace(string s) {
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                s.insert(i,"%20");
                i = i + 3;
                s.erase(i,1);
            }
        }
        return s;
    }
};
int main()
{
    string s = "     ";
    Solution s1;
    s1.replaceSpace(s);
    system("Pause");
}
