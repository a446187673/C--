#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//151. 颠倒字符串中的单词 https://leetcode.cn/problems/reverse-words-in-a-string/
class Solution {
public:
    string reverseWords(string s) {
        string res;
        auto it = s.begin();
        auto bgin = it;
        while(it != s.end())
        {
            if(*it == ' ')
            {   
                if(bgin != it)
                {
                    res.insert(res.begin(),bgin,it);
                    res.insert(res.begin(),' ');
                }
                it++;
                bgin = it;
            }
            else
                it++;
        }
        //最后不是空格，无法插入最后一个单词
        if(*bgin != ' ')
            res.insert(res.begin(),bgin,it);
        //最后是空格
        if(res[0] == ' ')
            res.erase(0,1);
        return res;
    }
};
int main()
{
    
    Solution s1;
    string s = " world  hello ";
    s1.reverseWords(s);
    system("Pause");
}
