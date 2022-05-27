#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//9. 回文数 https://leetcode.cn/problems/palindrome-number/
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        for (int i = 0,j = s.size()-1; i <= j; i++,j--)
        {
            if(s[i] != s[j])
                return false;
        }
        return true;
    }
};
int main()
{
    
    system("Pause");
}
