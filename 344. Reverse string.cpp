#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//344. 反转字符串 https://leetcode.cn/problems/reverse-string
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0,j = s.size() - 1; i < s.size()/2; i++,j--)
        {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
        }
        
    }
};
int main()
{
    Solution s1;
    vector<char> s{'h','e','l','l','o'};
    s1.reverseString(s);
    system("Pause");
}
