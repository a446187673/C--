#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//763. 划分字母区间 https://leetcode.cn/problems/partition-labels/
//思路 找出与段开头字母相同的，且下标最大的字母，进行分割
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        vector<int> record(24,0);
        for (int i = 0; i < s.size(); i++)
        {
            record[s[i]-'a'] = i;
            cout<<s[i]<<"|";
        }
        // for (auto i : record)
        // {
        //     cout<<i<<" ";
        // }
        int left = 0;
        int right = 0;
        
        for (int i = 0; i < s.size(); i++)
        {
            // cout << s[i] << "|";
            right = max(right,record[s[i]-'a']);
            if(right == i)
            {
                res.push_back(right - left+1);
                left = right + 1 ;
            }
        }
        return res;
    }
};
int main()
{
    Solution s1;
    vector<int> res = s1.partitionLabels("ababcbacadefegdehijhklij");
        // for (auto i : res)
        // {
        //     cout<<i;
        // }

    system("Pause");
}
