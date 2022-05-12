#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>

using namespace std;
//738.单调递增的数字 https://leetcode.cn/problems/monotone-increasing-digits/
//思路 从后向前遍历，将后一位小于前一位的情况记录下来，最后统一变换
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strnum = to_string(n);
        int index = -1; //记录位置
        for(int i = strnum.size()-1;i>0;i--)
        {
            if(strnum[i] <= strnum[i-1])
            {
                index = i;
                strnum[i-1] = strnum[i-1]-1;
            }
            
        }
        if(index != -1)
        {
            for (int i = index; i < strnum.size(); i++)
            {
                strnum[i] = '9';
            }
            
        }
        return stoi(strnum);
        
    }
};
int main()
{
    Solution s1;
    cout<<s1.monotoneIncreasingDigits(101);
    system("Pause");
}
