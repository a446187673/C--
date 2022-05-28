#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;
//1021. 删除最外层的括号 https://leetcode.cn/problems/remove-outermost-parentheses/
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string res;
        for(char i : s)
        {
            if( i == ')')
                st.pop();
            if(!st.empty())
                res.push_back(i);
            if(i == '(')
                st.push(i);
        }
        return res;
    }
};
int main()
{
    Solution s1;
    cout<<s1.removeOuterParentheses("(())()");
    
    system("Pause");
}
