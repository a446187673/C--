#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//6. Z 字形变换 https://leetcode.cn/problems/zigzag-conversion/
//字符串
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.size() <= 1)
            return s;
        if(numRows == 2)
        {
            string res;
            for (int i = 0; i < s.size(); i+=2)
                res.push_back(s[i]);
            for (int i = 0; i < s.size(); i+=2)
                res.push_back(s[i]);
            return res;
            
        }
        vector<vector<char>> strs(numRows,vector<char>(s.size(),' '));
        int count = 0;
        int temp = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if(count % (numRows-1) != 0)
            {
                //不是全填充
                temp--;
                strs[temp][count] = s[i];
                count++;
                if(count % (numRows-1) == 0)
                    temp--;
            }
            else
            {
                
                strs[temp][count] = s[i];
                temp++;
            }
            if(temp == numRows)
            {
                count++;
                temp--;
            }
        }
        string res;
        for(auto i : strs)
        {
            for(auto j : i)
            {
                cout<<j;
            }
            cout<<endl;
        }
        return res;
    }
};
int main()
{
    Solution s1;
    
    s1.convert("ABCDE",3);
    system("Pause");
}
