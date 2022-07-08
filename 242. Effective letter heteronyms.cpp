#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//242. 有效的字母异位词 https://leetcode.cn/problems/valid-anagram/
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> nums(26,0);
        for(char i : s)
            nums[i - 'a']++;
        for(char i : t)
            nums[i - 'a']--;
        for(int i : nums)
            if( i != 0)
                return false;
        return true;
    }
};
int main()
{
    
    system("Pause");
}
