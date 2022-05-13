#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
// 面试题 01.05. 一次编辑 https://leetcode.cn/problems/one-away-lcci/
//思路 模拟
class Solution {
public:
    bool oneEditAway(string first, string second) {
        int a = first.size()-second.size();
        if(abs(a)<= 1)
        {
            if(a == 0)
            {
                int comp = 0;
                for (int i = 0; i < first.size(); i++)
                {
                    if(first[i] != second[i])
                        comp++;
                }
                    if(comp>1)
                        return false;
            }
            else
            {
                string longs;
                string shorts;
                if(a == 1)
                {
                   longs = first;
                   shorts = second;
                }
                else
                {
                    longs = second;
                    shorts = first;
                }
                int flag=0;
                auto it = shorts.begin();
                for (int i = 0; i < longs.size(); i++)
                {
                    if(*it!=longs[i])
                    {
                        it = shorts.insert(it,first[i]);
                        flag++;
                    }
                        it++;
                    if(flag >1)                       
                        return false;
                }
            }
            return true;
        }
        else 
            return false;
    }
};
int main()
{
    Solution s1;
    cout<<s1.oneEditAway("a"
,"ab");
    string s= "abc";
    auto it = s.begin();
    it++;
    s.insert(it,'d');
    it++;
    s.insert(it,'d');
    it++;
    cout<<s;
    system("Pause");
}
