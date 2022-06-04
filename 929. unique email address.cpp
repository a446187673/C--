#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<algorithm>

using namespace std;
//929. 独特的电子邮件地址 https://leetcode.cn/problems/unique-email-addresses/
//哈希表 模拟
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int res = 0;
        unordered_set<string> local;
        unordered_set<string> internet;
        for(string str : emails)
        {
            int i = 0;
            bool flag = false;
            for (;;i++)
            {
                if(str[i] == '+')
                {
                    string s;
                    for (int k = 0; k < i; k++)
                    {
                        if(str[k] == '.')
                            continue;
                        s.push_back(str[k]);
                    }
                    if(local.count(s) == 0)
                    {
                        res++;
                        flag = true;
                    }
                    local.emplace(s);
                    while (str[i] != '@')
                        i++;
                    break;
                }
                else if(str[i] == '.')
                    continue;
                else if(str[i] == '@')
                {
                    string s;
                    for (int k = 0; k < i; k++)
                    {
                        if(str[k] == '.')
                            continue;
                        s.push_back(str[k]);
                    }
                    if(local.count(s) == 0)
                    {
                        res++;
                        flag = true;
                    }
                    local.emplace(s);
                    break;
                }
            }
            int count = 0;
            int j = i+1;
            for(;j<str.size() - 4;j++)
                count++;
            string s2 = str.substr(i+1,count);
            if(flag == false && internet.count(s2) == 0)
                res++;
            internet.emplace(s2);

        }
        // cout<<local.size()<<"  "<<internet.size();
        return res;
    }
};
int main()
{
    Solution s1;
    vector<string> ss{"a@l.com","b@l.com","c@l.com"};
    cout<<s1.numUniqueEmails(ss);
    system("Pause");
}
