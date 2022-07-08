#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//28. 实现 strStr() https://leetcode.cn/problems/implement-strstr/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
            return 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            if(haystack[i] == needle[0])
            {
                int idx1 = i;
                int idx2 = 0;
                while(idx1 < haystack.size() && idx2 < needle.size())
                {
                    if(haystack[idx1] != needle[idx2])
                        break;
                    idx1++;
                    idx2++;
                }
                if(idx2 == needle.size())
                    return i;
            }
        }
        return -1;
    }
};
int main()
{
    Solution s1;
    string s = "hello";
    string n = "ll";
    s1.strStr(s,n);
    system("Pause");
}
