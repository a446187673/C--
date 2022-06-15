#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//498. 对角线遍历 https://leetcode.cn/problems/diagonal-traverse/
//数组 模拟
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        bool revers = true;
        for (int jl = 0; jl < mat[0].size(); jl++)
        {
            int j = jl;
            int i = 0;
            vector<int> temp;
            while (j >= 0 && i < mat.size())
            {
                temp.push_back(mat[i][j]);
                i++;
                j--;
            }
            if(revers == true)
            {
                reverse(temp.begin(),temp.end());
                revers = false;
            }
            else
            {
                revers = true;
            }
            for (int i : temp)
                res.push_back(i);
        }
        for (int il = 1; il < mat.size(); il++)
        {
            int j = mat[0].size() - 1;
            int i = il;
            vector<int> temp;
            while (j >= 0 && i < mat.size())
            {
                temp.push_back(mat[i][j]);
                i++;
                j--;
            }
            if(revers == true)
            {
                reverse(temp.begin(),temp.end());
                revers = false;
            }
            else
            {
                revers = true;
            }
            for (int i : temp)
                res.push_back(i);
        }
        return res;
    }
};
int main()
{
    vector<vector<int>> mat{{2,3}};
    Solution s1;
    s1.findDiagonalOrder(mat);
    
    system("Pause");
}
