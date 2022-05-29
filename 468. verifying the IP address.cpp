#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//468. 验证IP地址 https://leetcode.cn/problems/validate-ip-address/
class Solution {
public:
    int isIP6(string strs)
    {
        if(strs[strs.size()-1] == ':')
            return -1;
        int count = 0;
        int left = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            if(strs[i] == ':')
            {
                count++;
                string s = strs.substr(left,i-left);
                left = i+1;
                if(is6(s) == false)
                    return -1;
            }
        }
        string s = strs.substr(left,strs.size() - left);
        if(is6(s) == false || count != 7)
            return -1;
        return 6;
    }
    bool is6(string s)
    {
        if (s.size() == 0) //空字符
            return 0;
        if (s.size() > 4) //长度判断
            return 0;
        for (char i : s) //数字判断
        {
            if ((i >= '0' && i <= '9') || (i >= 'a' && i <= 'f') || (i >= 'A' && i <= 'F'))
                continue;
            else
                return 0;
        }
        return 1;
    }

    int isIP4(string strs)
    {
        if(strs[strs.size()-1] == '.')
            return -1;
        int left = 0;
        int count = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            if(strs[i] == '.')
            {
                count++;
                string s = strs.substr(left,i-left);
                left = i+1;
                if(is4(s) == false)
                    return -1;
            }

        }
        string s = strs.substr(left,strs.size() - left);
        if(is4(s) == false || count != 3)
            return -1;
        return 4;
    }
    bool is4(string s)
    {
        if (s.size() == 0 || s.size() > 4) //空字符
            return 0;
        if (s[0] == '0' && s.size() > 1) //前导0
            return 0;
        for (char i : s) //数字判断
            if (i < '0' || i > '9')
                return 0;
        
        int num = stoi(s);
        if (num < 0 || num > 255) //数字大小
            return 0;
        return 1;
    }


    string validIPAddress(string queryIP) {
        int IP = -1;
        for(char i : queryIP)
        {
            if(i == '.')
            {
                IP = isIP4(queryIP);
                break;
            }
            if( i == ':')
            {
                IP = isIP6(queryIP);
                break;
            }
        }
        if( IP == 4)
            return "IPv4";
        else if( IP == 6)
            return "IPv6";
        else
            return "Neither";
    }
};
int main()
{
    int i = stoi("1e1");
    cout<<i;
    system("Pause");
}
