#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
//1089. 复写零 https://leetcode.cn/problems/duplicate-zeros/
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        auto it = arr.begin();
        int size = arr.size();
        for(;it != arr.end();)
        {
            if(*it == 0)
            {
                it = arr.emplace(it,0);
                it++;
                it++;

            }
            else
                it++;
        }
        arr.resize(size);
    }
};
int main()
{
    Solution s1;
    vector<int> vec{1,0,2,3,0,4,5,0};
    s1.duplicateZeros(vec);
    system("Pause");
}
