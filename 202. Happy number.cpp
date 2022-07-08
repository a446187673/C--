#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<algorithm>

using namespace std;
//202. 快乐数 https://leetcode.cn/problems/happy-number/
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(set.count(n) == 0)
        {
            set.emplace(n);
            string num = to_string(n);
            int sum = 0;
            for(char i : num)
            {
                i = i-'0';
                sum += i*i;
            }
            n = sum;
            if(n == 1)
                return true;
        }
        return false;
    }
};
int main()
{
    Solution s1;
    s1.isHappy(19);
    system("Pause");
}
