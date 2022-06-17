#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//59. 螺旋矩阵 II https://leetcode.cn/problems/spiral-matrix-ii/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        int startx = 0;
        int starty = 0;
        int offset = 1;
        int count = 1;
        int loop = n/2;
        while(loop > 0)
        {
            int i,j;
            for (j = starty; j < starty + (n - offset); j++)
            {
                mat[startx][j] = count++;
            }
            
            for (i = startx; i < startx + (n - offset); i++)
            {
                mat[i][j] = count++;
            }

            for (; j > starty; j--)
            {
                mat[i][j] = count++;
            }
            
            for (; i > startx; i--)
            {
                mat[i][j] = count++;
            }
            
            startx++;
            starty++;
            loop--;
            offset+=2;
        }
        if (n % 2 == 1) {
            mat[n/2][n/2] = count;
        }
        return mat;
    }
};
int main()
{
    Solution s1;
    vector<vector<int>> vec;
    vec = s1.generateMatrix(5);
    for(auto v : vec)
    {
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    system("Pause");
}
