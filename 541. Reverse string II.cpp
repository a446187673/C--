#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//541. 反转字符串 II https://leetcode.cn/problems/reverse-string-ii/
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size())
                reverse(s.begin() + i, s.begin() + i + k );
            else
            // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
                reverse(s.begin() + i, s.end());
        }
        return s;
    }
};
int main()
{
    
    system("Pause");
}
