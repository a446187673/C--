#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//7. 整数反转 https://leetcode.cn/problems/reverse-integer/
class Solution {
public:
    int reverse(int x) {
        if(x >= 0 && x <= 9) //个位数判断
            return x;
        string s = to_string(x);
        bool negetive = false;
        if(s[0] == '-') //负数处理
        {
            s.erase(s.begin());
            negetive = true;
        }
        bool zero = true;
        string res;
        for (int i = s.size()-1; i >= 0; i--)
        {
            if(s[i] == '0' && zero == true)
                continue;
            if(s[i] != 0)
                zero = false;
            res.push_back(s[i]);    
        }
        if(res.size() > 10)//首位为0处理
            return 0;
        if(res.size() == 10) //超出范围处理
        {
            string ms = "2147483648";
            for (int i = 0; i < 10; i++)
            {
                if(res[i] < ms[i])
                    break;
                else if(res[i] > ms[i])
                    return 0;
            }
        }
        int r = stoi(res);
        if(negetive)
            r = -r;
        return r;
    }
};
int main()
{
    Solution s1;
    cout<<s1.reverse(1534236469);
    system("Pause");
}
