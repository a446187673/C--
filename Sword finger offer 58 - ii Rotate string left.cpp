#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//剑指 Offer 58 - II. 左旋转字符串 https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string temp = s.substr(0,n);
        s.erase(s.begin(),s.begin() + n);
        s.insert(s.size(),temp);
        return s;
    }
};
int main()
{
    
    system("Pause");
}
