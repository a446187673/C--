#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//459. 重复的子字符串 https://leetcode.cn/problems/repeated-substring-pattern/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s+s).find(s,1) != s.size();
    }
};
int main()
{
    
    system("Pause");
}
