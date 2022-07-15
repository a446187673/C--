#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;
//20. 有效的括号 https://leetcode.cn/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s)
        {
            if(c == '(') st.push(')');
            else if(c == '[') st.push(']');
            else if(c == '{') st.push('}');
            else if(st.empty() || st.top() != c)
                return false;
            else if(st.top() == c)
                st.pop();
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};
int main()
{
    
    system("Pause");
}
