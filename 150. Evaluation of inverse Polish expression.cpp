#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;
//150. 逆波兰表达式求值 https://leetcode.cn/problems/evaluate-reverse-polish-notation/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto c : tokens)
        {
            if( c.size() == 1 &&(c[0] == '+' || c[0] == '-' || c[0] == '*' || c[0] == '/'))
            {
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                if(c[0] == '+') st.push(x + y);
                else if(c[0] == '-') st.push(x - y);
                else if(c[0] == '*') st.push(x * y);
                else if(c[0] == '/') st.push(x / y);
            }
            else
                st.push(stoi(c));
        }
        return st.top();
    }
};
int main()
{
    vector<string> vec = {"4","13","5","/","+"};
    Solution s1;
    s1.evalRPN(vec);
    system("Pause");
}
