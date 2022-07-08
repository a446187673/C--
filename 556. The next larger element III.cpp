#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//556. 下一个更大元素 III https://leetcode.cn/problems/next-greater-element-iii/
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.size()-2;
        while (i >= 0 && s[i] >= s[i+1])
            i--;
        if(i < 0)
            return -1;
        else
        {
            int j = s.size()-1;
            while(i  < j && s[i] >= s[j])
                j--;
            swap(s[i],s[j]);
        }
        reverse(s.begin() + i + 1, s.end());
        long res = stol(s);
        return res>INT_MAX? -1 : res;
    }
};
int main()
{
    
    system("Pause");
}
