#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//944. 删列造序 https://leetcode.cn/problems/delete-columns-to-make-sorted/
//思路 依次遍历每一列比较即可
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        for(int i = 0; i < strs[0].size(); i++) //对列循环
        {
            for(int j = 1; j< strs.size();j++) //对行循环
            {
                if(strs[j][i] < strs[j-1][i])
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
int main()
{
    
    system("Pause");
}
