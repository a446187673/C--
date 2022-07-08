#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;
//383. 赎金信 https://leetcode.cn/problems/ransom-note/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int,int> map;
        for(char i : magazine)
            map[i]++;
        for(char i : ransomNote)
        {
            if(map[i] == 0)
                return false;
            else
                map[i]--;
        }
        return true;
    }
};
int main()
{
    
    system("Pause");
}
