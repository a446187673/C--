#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//942. 增减字符串匹配 https://leetcode.cn/problems/di-string-match/
//贪心算法 + 双指针
//思路 1.既然都是左边的数比右边的数，那么在每次比较时，保证每次左边的数是能取到的的最大值，右边的数为能取到的最小值即可
class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> nums;
        vector<int> res;
        for (int i = 0; i < s.size()+1; i++) //创建一个数组用于取值，也可以单用一个数字
            nums.push_back(i);
        int left = 0;
        int right = nums.size()-1;
        int i = 0;
        while( i < s.size()) //每次都从最大值和最小值取，取后推进指针，保证下次取的依旧是最大或最小值。
        {
            if(s[i] == 'I')
            {
                res.push_back(nums[left]);
                left++;
            }
            else if(s[i] == 'D')
            {
                res.push_back(nums[right]);
                right--;
            }
            i++;
        }
        res.push_back(nums[right]); //最后left ==right，推入任意一个指针的数即可。
        return res;
        
    }
};
int main()
{
    Solution s1;
    vector<int> res = s1.diStringMatch("IDIDI");
    for(auto i : res)
    cout<<i;
    system("Pause");
}
